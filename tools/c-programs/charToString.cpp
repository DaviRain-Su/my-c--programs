#include <iostream>
#include <string>
#include <string.h>

void fn(std::string &s)
{
    const char *tmp  = "hello, world!";
    s = tmp;
}

int main()
{
   const char *tmp = "hello, world";

    std::string s1;
    
    fn(s1);
    //strcpy(const_cast<char*>(s1.data()), tmp);

    std::cout << "this s1 is " << s1 << std::endl;
    
    return 0;
}

