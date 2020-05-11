
#include <iostream>
#include <stdio.h>

class Trace {
public:
    Trace () { noisy = 0; f = stdout; }
    Trace (FILE* ff) { noisy = 0; f = ff; }
    void print(char* s) { if(noisy) fprintf(f, "%s", s); }
    void on() { noisy = 1; }
    void off() { noisy = 0; }
private:
    int noisy;
    FILE* f;
};

int main()
{
    Trace t(stderr);
    t.on();
    t.print("begin main()\n");
    //main body
    t.print("end main()\n");
    return 0;
}

