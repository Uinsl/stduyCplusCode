#pragma once
#pragma once

template<typename T>
class myVector
{

public:


	int size() { return m_size; }

	T& operator[](int index) {
		cout << "T& []" << endl;
		return m_data[index];
	}

	const T& operator[](int index) const {
		return m_data[index];
	}

	T* Data() {
		return m_data;
	}

	const T* Data() const {
		return m_data;
	}

	void PushBack(const T& data) {
		realloc(m_data, sizeof(T) * m_memSize); //sizeof(int) 32位 4字节，64位 8字节。
		//m_data[0] = data;
		//m_size++;
		*(m_data + m_size) = 0;
		//m_size++;
	}


private:
	// 我真是一个天才。
	T* m_data;//起始指针
	size_t m_size;//下标
	size_t m_memSize;//字节个数
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

*/


