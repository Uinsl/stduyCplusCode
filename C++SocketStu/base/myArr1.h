template<typename T, size_t S>
class myArray
{
public:

	int size() { return S; }

	T& operator[](int index) {
		//cout << "T& []" << endl;
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

	/*
	T& operator[](int index) const {
		cout << "T& [] const" << endl;
		return m_data[index];
	}*/

	const int& mmx(int index) const {
		// const 限定符修饰的返回的值，必定是cosnt类型?是const引用类型
		// 所以，t& => const 时，t 必须为const
		// 当类定义为cosnt时，mmx 必须定义为const 才能被使用
		// 当mmx int 是 int& 类型时，
		// https://blog.csdn.net/HackCyberX/article/details/133381523
		cout << "mmx" << endl;
		//return m_data[index];
		return 99;
	}

private:
	T m_data[S];
};




#if 0
#include <iostream>
using namespace std;
#define wait std::cin.get();

//#include "myVector.h"

template<typename T, size_t S>
class myArray
{
public:

	int size() { return S; }

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

	const T* Data() const{
		return m_data;
	}

	/*
	T& operator[](int index) const {
		cout << "T& [] const" << endl;
		return m_data[index];
	}*/

int& mmx(int index) const {
	// const 限定符修饰的返回的值，必定是cosnt类型?是const引用类型
	// 所以，t& => const 时，t 必须为const
	// https://blog.csdn.net/HackCyberX/article/details/133381523
	cout << "mmx" << endl;
	return m_data[index];
}

private:
	T m_data[S];
};

int main()
{
	int size = 5;
	myArray<int, 5> data;
	//const auto& ary = data;
	auto& ary = data;

	//memset(data.Data(), 0, data.size() * sizeof(int));
	for (int i = 0; i < 5; i++) {
		ary[i] = 5;
	}
	for (int i = 0; i < 7; i++) {
		cout << "ary[" << i << "] = " << ary[i] << endl;
	}

	//myVector<int> davec;
	//davec.PushBack(1);
	//for (int i = 0; i < davec.size(); i++) {
		//cout << "davec[" << i << "] = " << davec[i] << endl;
	//}

	int ss[5] = { 0,1,2,3,4 };
	*(ss + 1) = 99;
	cout << "ss[1] = " << *(ss + 1) << endl;

	int* p;
	realloc(p, sizeof(int));
	*p = 1;
	wait
}

#endif


/*
Like I said,
typically you would have both T& operator[](size_t)
and const T& operator[](size_t) const so you can use
the function on non-const objects
to get non-const references,
and on const objects to get const references

The const qualified version should return a const reference
*/






