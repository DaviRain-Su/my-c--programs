#include <iostream>
#include <random>
#include <ctime>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_real_distribution;


int main()
{

    default_random_engine e(time(NULL));
    uniform_real_distribution<float> Unifom(-1.0, 1.0);
    
    for(int i = 0; i != 10; ++i)
    {
        std::cout << Unifom(e) << std::endl;
    }
    return 0;
}

