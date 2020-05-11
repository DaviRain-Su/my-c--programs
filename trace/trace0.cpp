
#include <iostream>
#include <stdio.h>

class Trace {
public:
    void print(char* s) { printf("%s", s); }
};
int main()
{
    Trace t;
    t.print("begin main()\n");
    //main body
    t.print("end main()\n");
    return 0;
}

