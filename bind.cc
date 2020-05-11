#include <iostream>
#include <functional>
#include <memory>
#include <string>

using std::string;

using FuncCallbac = std::function<void()>;

void hello(){
    std::cout << "hello world" << std::endl;
}
void world(){
    std::cout << "world hello" << std::endl;
}
struct Test
: public std::enable_shared_from_this<Test>   
{
    using TestPtr = std::shared_ptr<Test>;
    using TestCallback = std::function<void(const TestPtr &)>;
    
    Test(){}
    ~Test(){}
private:
    void f1(const string &msg){
        std::cout << "connection" << msg << std::endl;
    }
    void f2(const string &msg){
        std::cout << "message"  << msg << std::endl;
    }
    void f3(const string &msg) {
        std::cout << "close" << msg <<  std::endl;
    }
public:
    void Connection(const string & msg){
        setOnConnection(std::bind(&Test::f1, this, msg));
    }
    void Message(const string &msg){
        setOnMessage(std::bind(&Test::f2, this, msg));
    }
    void Close(const string &msg){
        setOnClose(std::bind(&Test::f3, this, msg));
    }
private:
    void setOnConnection(const TestCallback& cb){
        _onConnection = std::move(cb);
    }
    void setOnMessage(const TestCallback& cb){
        _onMessage = std::move(cb);
    }
    void setOnClose(const TestCallback& cb){
        _onClose = std::move(cb);
    }

public:

    void hand_all(){
        handleOnConnection();
        handleOnMessage();
        handleOnClose();
    }
    void handleOnConnection(){
        if(_onConnection){
            _onConnection(shared_from_this());
        }
    }
    void handleOnMessage(){
        if(_onMessage){
            _onMessage(shared_from_this());
        }
    }
    void handleOnClose(){
        if(_onClose){
            _onClose(shared_from_this());
        }
    }
private:
    TestCallback _onConnection;
    TestCallback _onMessage;
    TestCallback _onClose;
};

int main()
{
    string msg {"Hello Rust!"}; 
    Test mytest;
    mytest.Connection(msg);
    mytest.Message(msg);
    mytest.Close(msg);
//    mytest.hand_all();
    mytest.handleOnConnection();   

    return 0;
}

