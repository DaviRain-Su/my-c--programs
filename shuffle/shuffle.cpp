#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

template<typename T>
void shuffle(T *list, size_t len)
{
    srand(time(NULL));
    int i = len, j;
    T temp;
    if(i == 0) return;
    while(--i){
        j = rand() % (i+1);
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}
template<typename T>
void Print(T *list, size_t len){
    for(size_t i = 0; i != len; ++i){
        cout << list[i] << " ";
    }
    cout << endl;
}
int main()
{

   int Vec[100]  = {0};
#if 1
   for(size_t i = 0; i != 100; i++){
       Vec[i] = i;
   }
   cout << endl;
#endif
   //lambda
   auto Printfn = [](int * list, size_t n){
       for(size_t i = 0; i  < n; i++){
           cout << list[i] << " ";
       }
       cout << endl;
   };

   Printfn(Vec, 100);
   shuffle(Vec, 100);
   Print(Vec, 100);



    return 0;
}

