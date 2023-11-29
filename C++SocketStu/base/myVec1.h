#pragma once

using namespace std;
//#include <iostream>  
//#include <new>  

template <class T>
class MyVector {
public:
    T* data; // 指针指向地址
    int size;  //保存的元素个数
    int capacity;  //内存大小

public:

    MyVector()
    {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

    ~MyVector() {
        delete[] data;
    }

    void push_back(T value) {
        if (size == capacity) { //判断当前存储的个数是否要超过分配的内存
            cout << "capacity 1 = " << capacity << endl;
            capacity <<= 1; //?
            cout << "capacity 2 = " << capacity << endl;
            T* new_data = new T[capacity];
            for (int i;i < size;i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size] = value;
        size++;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int size() {
        return size;
    }

};



/*

1、malloc
https://www.cnblogs.com/imreW/p/17061649.html
int* p;
p = malloc(sizeof(int));

2、calloc
http://www.manongjc.com/detail/31-gtpbxfovxtgwjrm.html
int *ptr;
ptr = (int *)calloc(5, sizeof(int));

3、realloc()
https://www.cnblogs.com/klchang/p/5719470.html
“ C 语言中 malloc、calloc、realloc 和free 函数的使用方法 ”
头文件：stdlib.h
声明：void * realloc(void * p,int n);
含义：重新分配堆上的void指针p所指的空间为n个字节，同时会复制原有内容到新分配的堆上存储空间。
注意，若原来的void指针p在堆上的空间不大于n个字节，则保持不变。
返回值：同malloc() 函数

栈只能用来保存临时变量、局部变量和函数参数。
在函数返回时，自动释放所占用的存储空间。
而堆上的内存空间不会自动释放，直到调用free()函数，才会释放堆上的存储空间。

https://www.bilibili.com/video/BV1cN4y177nU



int* p1;
p1 = malloc(sizeof(int)*1);  // malloc 申请空间
p1[0] = 999;

扩容1
// 申请一个更大的空间
int* p2;
p2 = malloc(sizeof(int)*1);

//使用memcpy，把p1内容复制给p2

int arr1[10] = {1, 2, 3, 4, 5};
int arr2[10];
size_t n = 3; // 复制前3个元素
memcpy(arr2, arr1, n * sizeof(int)); //arr2的内容将是{1, 2, 3}。

data  = p2 ；


扩容2：
realloc函数

int *arr1 = (int *)malloc(10 * 4);//10个int ，一个int 4字节
for（int v in arr1）{
	v = 1 2 3 4 5 6 7 8 9 0
}

int* arr2;
arr2 = realloc(arr1, 10 * sizeof(int));	// 将arr指向的内存块的大小改为10个整数的空间， arr1 的数据也会被复制出来

// realloc(arr1, 3 * sizeof(int));// 缩容1

// 使用arr指向的内存块进行其他操作...
free(arr); // 释放内存块


扩容3 : 使用new 分配内存
T* arr3 = new int[size];
把arr1 的内容复制到 arr3
把mdata 指向arr3


在C++中，用于初始化数组内存的函数有：

new 运算符：使用 new 运算符可以动态地分配内存并初始化数组。例如：
int* arr = new int[10]; // 分配10个整数的内存空间并自动初始化为0
文心一眼 我去你妈的

calloc 函数：使用 calloc 函数可以在分配内存的同时将其初始化为0。例如：
int* arr = (int*)calloc(10, sizeof(int)); // 分配10个整数的内存空间并初始化为0

直接初始化：在定义数组时，可以直接使用初始化列表来初始化数组元素。例如：
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 初始化数组元素

calloc 和 new 区别：
内存分配方式：new操作符通过调用构造函数来初始化对象，而calloc函数通过调用构造函数将内存初始化为0。

返回类型：new操作符返回一个对象指针，而calloc函数返回一个指向已分配内存的指针。
因此，使用new操作符时不需要进行强制类型转换，而使用calloc函数时需要将返回的指针转换为所需类型的指针。
内存分配失败时的返回值：如果内存分配失败，new操作符将抛出一个异常，而calloc函数将返回NULL。

内存释放：使用new分配的内存需要在不再使用时显式地释放，以避免内存泄漏。使用calloc分配的内存可以使用free函数释放。


*/

/*

// 定义一个模板类 MyVector，可以存储任意类型的元素
template <class T>
class MyVector {
private:
    // 当前向量的大小，即元素的个数
    int size;
    // 向量的容量，即当前分配的内存空间大小
    int capacity;
    // 存储元素的动态数组
    T* data;

public:
    // 构造函数，初始化向量的大小为0，容量为2，并为元素数组分配内存空间
    MyVector() {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

    // 析构函数，释放元素数组的内存空间
    ~MyVector() {
        delete[] data;
    }

    // 向量中添加一个元素，如果当前容量已满，则扩展容量并复制原有元素到新的内存空间
    void push_back(T value) {
        if (size == capacity) {
            capacity *= 2;  // 当size达到当前capacity限制时，将capacity翻倍，以容纳更多的元素
            T* new_data = new T[capacity];  // 分配新的内存空间来存储元素
            for (int i = 0; i < size; i++) {  // 将原有元素复制到新的内存空间中
                new_data[i] = data[i];
            }
            delete[] data;  // 释放原有内存空间
            data = new_data;  // 将指向新内存空间的指针赋值给data，以便后续操作新元素
        }
        data[size] = value;  // 在当前容量未满的情况下，将新元素添加到data数组的末尾，并更新size的值
        size++;  // 更新size的值，表示向量中元素的数量增加了一个
    }

    // 从向量中删除最后一个元素，并释放其占用的内存空间
    void pop_back() {
        if (size > 0) {  // 如果向量不为空（即size大于0），则执行pop_back操作
            size--;  // 更新size的值，表示向量中元素的数量减少了一个
        }
    }

    // 通过索引访问向量中的元素，如果索引越界则抛出一个异常（out_of_range）
    T& operator[](int index) {
        if (index < 0 || index >= size) {  // 检查索引是否在有效范围内（0到size-1）
            throw std::out_of_range("Index out of range");  // 如果不在有效范围内，则抛出一个异常
        }
        return data[index];  // 如果索引在有效范围内，则返回data数组中相应位置的元素引用（指针）
    }

    // 返回向量中元素的数量（size的值）
    int size() {
        return size;  // 返回size的值作为向量中元素的数量（size）
    }
};









*/

