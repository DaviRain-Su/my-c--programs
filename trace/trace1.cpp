
#include <iostream>
#include <stdio.h>

class Trace {
public:
    Trace () { noisy = 0; }
    void print(char* s) { if(noisy) printf("%s", s); }
    void on() { noisy = 1; }
    void off() { noisy = 0; }
private:
    int noisy;
};
int main()
{
    Trace t;
    t.off();
    t.print("begin main()\n");
    //main body
    t.print("end main()\n");
    return 0;
}

