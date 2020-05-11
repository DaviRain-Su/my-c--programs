#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;
struct Test {

    shared_ptr<char*> ptr_alloc;
    static const int SIZE = 30;
    Test()
        : ptr_alloc(std::make_shared<char*>(new char(SIZE)) ){
            std::cout << "Test()" << std::endl;
        }
    ~Test() {
        std::cout << "~Test()" << std::endl;    
    }

    void set_Test(char *lhs) {
        auto ptr = ptr_alloc.get();
        *ptr = lhs;
    }

    void display(){
      std::cout << "use count is " << ptr_alloc.use_count() << std::endl;
      std::cout << *ptr_alloc  << std::endl;;
    }


};
int main()
{
    Test my_test;
    my_test.display();

    my_test.set_Test("Hello world!");
    my_test.display();
    return 0;
}

