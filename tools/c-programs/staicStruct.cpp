#include <iostream>
#include <string.h> // for msmset
//static const int _SIZE = 1024;

struct msg{
    static const int _SIZE = 1024;
    long type;
    char text[_SIZE];
    
    msg() : type(0){
        memset(text, '\0', sizeof(text));
    }
};
int main()
{
    std::cout << "sizeof struct msg " << sizeof(msg) << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

