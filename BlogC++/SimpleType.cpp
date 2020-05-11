/*-std=c++1z*/
#include <iostream>
#include <string>
//pre C++11 class:
struct SimpleType {
    int field;
    std::string name;

    SimpleType () : field(0), name("Hello World") {}
};

// Since C++11:
struct SimpleTypeC11 {
    int field = 0;
    std::string name  { "Hello Wold" };
    SimpleTypeC11(){}  
};
/*  
 *  
 *  C++17, 可以使用内联变量来初始化静态数据成员　
 *　无需className 在相应的cpp文件中进行定义,
 *  编译器保证所有编译单元只能看到静态成员的一个定义
 *  
 *
 *  注意，对于常量整数静态字段，　即使在C++98中, 我们也可以"就地"
 *  初始化他们。
 *
 * */
struct  OtherType {
    static const int value = 10;
    static inline std::string className = "Hello Class";
    OtherType() {  }
};
// 非静态数据成员初始化　NSDMI
int main()
{
    std::cout << "Hello world" << std::endl;
    SimpleType t;

    std::cout << "filed : " << t.field << "\n" <<  
                "name : "  << t.name << std::endl;
    
    SimpleTypeC11 t1;
    std::cout << "filed : " << t1.field << "\n" <<
                "name : " << t.name << std::endl;

    OtherType t2;
    std::cout << "value : " << t2.value << "\n" <<
                "name : " << t2.className << std::endl;
    return 0;
}

