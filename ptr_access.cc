#include <iostream>
#include <memory>

using std::unique_ptr;
int main()
{
    unique_ptr<int> ptr_int(new int(5));

    std::cout << "this is unique_ptr " << *ptr_int << std::endl;

    return 0;
}

