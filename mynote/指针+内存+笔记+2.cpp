#include <iostream>
using namespace std;

int mysum(int a,int b);
void zzTest();

//class
class MyClass {
public:
    static int class_var;  // 类作用域变量
};
int MyClass::class_var = 30;


int main(){
    system("chcp 65001");
    
    zzTest();
    int ret;
    ret = mysum(10,12);

    cout << "Hel=" << ret << endl;

    cout << "class var: " << MyClass::class_var << endl;

    string sa = "mystring";
    sa = "my2ttt";
    //? sa的值怎么会改

    system("pause");
    return 0;
}

//
int mysum(int a,int b){
    return a+b;
}

void zzTest(){

    int xa = 110;
    cout << "xa 变量的地址： " << &xa << endl; //0x605F0E
    cout << " * (&xa) = " << *(&xa) << endl; // 110


    int* p;
    int ma = 999;
    p = &ma; // 在指针变量中存储 var 的地址
    cout << "ma 变量的地址： " << &ma << endl;
    cout << "指针p存储（&ma）的地址,p = " << p <<endl;
    cout << "指针p地址的值, *p = " << *p << endl;
    cout << "指向，变量（指针p）的地址(类似&ma), &p = "<< &p <<endl;
}



/*
引用
int i = 10;
int& r= i;
https://www.runoob.com/cplusplus/cpp-references.html 



*/

/*
栈：在函数内部声明的所有变量都将占用栈内存。
堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。

ma 变量的地址： 0x61fda4
指针p存储（&ma）的地址,p = 0x61fda4
指针p地址的值, *p = 999
指向，变量（指针p）的地址(类似&ma), &p = 0x61fda8 //?只查4

地址偏移，p 和 &p？


https://www.zhihu.com/question/35893484

  &p=0xcafebabe        p=0xfeedbeef         *p=0xdeadbeef    <-- memory address

+--------------+    +---------------+    +----------------+
| p=0xfeedbeef | -> | *p=0xdeadbeef | -> | **p=0x01234567 |  <-- memory contents
+--------------+    +---------------+    +----------------+

内存是怎么保存变量的？
https://zhuanlan.zhihu.com/p/279796054

内存的地址空间---
https://zhuanlan.zhihu.com/p/582860835
1、物理地址（Physical Address）是内存中真实的地址，它是由CPU生成的，用来访问实际的内存单元。
2、地址空间分为物理地址空间和逻辑地址空间。

理解为：
内存最小存储单位是，bit(1 个 bit 只能表示两个状态)，8个 bit 为一组，命名为 byte。
每个byte --- 都是有编号的，比如0x0001，0x0002
编号怎来-内存的地址空间
CPU通过主板和内存条，系统生成，byte编号。
也就是int a ,  &a = 0x61fda4; 

具体byte编号怎么转换成0x0061 fda4? 
可以通过运算符 & 来取得变量实际的地址，这个值就是变量所占内存块的起始地址。
0x0001 4位16进制
0x0000 0001 8位16进制
win10 64位 单个byte的编号 = 0x61fda4 ？？


C++中显示变量地址均为十六进制的
0x61fda4?  6位16进制
008FFD98


a，int类型，4字节， 4 个字节
例如 int a =999;
999 换算成2进制就是： 
0000 0011 1110 0111
分别占用4个字节

*/




/*

signed int = int
long int 平台不同，字节不同


---------------------左右值---------------------------------
左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。
左值可以出现在赋值号的左边或右边。

右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。
右值是不能对其进行赋值的表达式，
也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

变量是左值，因此可以出现在赋值号的左边。
数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。
下面是一个有效的语句
int g = 20;
g 变量 左值
20 是右值

左值与指针
https://zhuanlan.zhihu.com/p/376345242

int num = 10;
int &b = num; //正确
int &c = 10; //错误
const int &b1 = num;
const int &c1 = 10;


https://bbs.huaweicloud.com/blogs/285313
int a, *p;
...
p = &a;
*p = 20;

//下面是这些变量的声明
int a = 112, b = -1;
float c = 3.14;
int *d = &a;
float *e = &c;

----------------------------------------------

// 全局变量声明
int g = 20;
int main ()
{
  // 局部变量声明
  int g = 10;
  cout << g;
}
g=10;



'\0'在c语言的字符串中表示字符串的结尾
就lz给的上下文环境中，if(ch[i][j]>'\0')判断该字符是否是字符串的结尾符


'\0'就是0
在C中作为字符串的结束标志，C标准库中对字符串的处理都会以\0作为字符串结束标志
如过你定义字符串常量，如"1234"，编译器会自动在末尾填\0

*/