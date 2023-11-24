/*
#if 1
#include <iostream>
using namespace std;
#define wait std::cin.get();
int main()
{

	wait
}

#endif

*/


#if 1
#include <iostream>
using namespace std;
#define wait std::cin.get();



template<typename T, size_t S>
class myArray
{
public:
	constexpr int size() const { return S; }

	T& operator[](int index) {
		return m_data[index];
	}

	//auto& arrayReference = data;
	T* operator[](int index) {
		return m_data[index];
	}

	

private:
	T m_data[S];
};


int main()
{
	int size = 5;
	myArray<int, 5> data;

	int a[2] = { 1,2 };
	auto& b = a;//????????

	auto& arrayReference = data;//const 指针时
	//const auto& arrayReference = data;//const 指针时

	for (int i = 0;i <= data.size();i++) {
		data[i] = i; //T& 
		
		cout << data[i] << endl;
	}
	//arrayReference[0] = 99;//const 引用 只能绑定在对象，不能绑定到常量



	for (int i = 0;i <= data.size();i++) {
		cout << data[i] << endl;
		cout << arrayReference[i] << endl;//
	}


	wait
}

#endif



#if 0
#include <iostream>
#include <array>
using namespace std;
// 
// int val = 12;
// int& func()
// https://c.biancheng.net/view/195.html
// P91
// https://www.bilibili.com/video/BV1gk4y1r7UH
// const int& func()
// https://zhuanlan.zhihu.com/p/256423512
// 左值 右值 左值引用 右值引用
// https://blog.csdn.net/m0_59938453/article/details/125858335
// 
// 左值函数返回值和变量返回值 区别:
// https://blog.csdn.net/idream68/article/details/115404171
// https://blog.csdn.net/m0_66249378/article/details/128388531
// 
// 等号是否会调用拷贝构造函数
// https://blog.csdn.net/ftimes/article/details/109321521
// 
// 左值引用返回值
// https://www.cnblogs.com/david-china/p/17080072.html
// int a = b ; 会
// int d; d = b； 不会copy
// int& getVar 不会 int getVar 会 ；
// 怎么证明

int& getVar() {// getVar 返回的是什么东西 int* 同问。
	static int val;
	cout << "val = " << val << endl; // 0x00007FF71B48F444  00 00 00 00
	return val;
}

int* getVar2() {
	int bb = 121;
	return &bb;
}


template<typename T, size_t S>
class myArray
{
public:
	constexpr int size() const { return S; }

	T& operator[](size_t index) {
		return m_data[index];
	}

	const T& operator[](size_t index) const { return m_data[index]; }

	T* Data() { return m_data; }
	const 	T* Data() const { return m_data; }
private:
	T m_data[S];
};



class Student {
public:
	Student() {
		cout << "Student() create" << endl;
	}
	Student(const Student& a) {
		cout << "Student() copy" << endl;
	}

	Student& operator=(Student& a) {
		cout << "Student() copy" << endl;
		return a; //因为a传进来是const 
	}

	int& GetAge() { // GetAge 返回的是什么东西 int* 同问。
		return m_age;
	}

	const int& GetAgeConst() {
		mm = 8;
		m_age = 999;
		return m_age;
	}

	void ShowAge() {
		cout << "Age: " << m_age << endl;
	}

private:
	int m_age = 0;
	int mm = 1;

};

Student t1;

Student getstu() {
	return t1;
}

Student& getstu2() {
	return t1;
}


int main() {
	int size = 5;
	myArray<int, 5> data;
	data.size();
	for (int i = 0; i < data.size(); i++) {
		data[i] = i;
		//cout << data[i] << endl;
	}

	for (int i = 0; i < data.size(); i++) {
		//data[i] = 2;
		cout << data[i] << endl;
	}
	int* mp;
	//mp = getVar();
	mp = &(getVar());

	cout << "getvar = " << getVar() << endl;

	Student a1 = getstu(); //调用copy
	Student a2 = getstu2();//? =号呢？//调用copy
	//getstu();//调用copy
	//getstu2();//不会调用copy 这应该就是左值引用返回值的用处。

	//Student a1 ; //调用copy
	//Student a2 ;//? =号呢？//调用copy
	//a1 = getstu();
	//a2 = getstu2();


	getVar() = 99; //
	auto a = getVar();//返回的是地址 &m_age ? *m_age? // 0x000000E4599FF874 63 00 00 00    等同 int a = 99;
	int aa = getVar(); //0x000000E4599FF894   63 00 00 00  等同  int aa = 99;
	int ac = a;

	cout << "&getvar = " << &(getVar()) << endl; //0x00007FF67EC3F444 99 就是static int val

	Student stu;
	stu.ShowAge();

	stu.GetAge() = 5; // 会修改成员变量的值
	stu.ShowAge();

	//stu.GetAgeConst() = a8; // 编译器会报错
	stu.ShowAge();




	//const auto& arrayReference = data;
	//arrayReference[1] = 2;

}
#endif 






// 拷贝2 move
// https://zhuanlan.zhihu.com/p/637590612
// 傻逼C++报错 https://blog.csdn.net/huanhuan59/article/details/84841795
// 找到【项目属性】，点击【C++】里的【预处理器】，对【预处理器定义】进行编辑，在里面加入一段代码：_CRT_SECURE_NO_WARNINGS。
#if 0
#include <iostream>
using namespace std;
#define wait std::cin.get();
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
class String
{

private:
	char* _buf;

public:
	String(const char* buf)
	{
		cout << "构造函数" << endl;
		_buf = new char[strlen(buf) + 1];
		strcpy(_buf, buf);  // 内存拷贝
	}

	String(const String& str)
	{
		cout << "拷贝构造函数" << endl;
		_buf = new char[strlen(str._buf) + 1];
		strcpy(_buf, str._buf); // 内存拷贝
	}

	String(String&& str)
	{
		cout << "右值拷贝构造函数" << endl;
		_buf = str._buf;        // 直接使用内存地址
		str._buf = nullptr;
	}

};


int main()
{
	String str("hello world!");
	String str1(str);
	String str2(std::move(str));
	wait
}

#endif 





#if 0
//笔记代码参考：https://www.cnblogs.com/zhangyi1357/p/16018810.html
#include <iostream>
#include <cstring>

class String {
public:
	String() = default;
	String(const char* string) {  //构造函数
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other) { // 拷贝构造函数
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	~String() {
		delete[] m_Data;
	}

	void Print() {
		for (uint32_t i = 0; i < m_Size; ++i)
			printf("%c", m_Data[i]);

		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity {
public:
	Entity(const String& name)//这里调用了构造函数
		: m_Name(name) {} // 这里调用看拷贝构造函数


	void PrintName() {
		m_Name.Print();
	}
private:
	String m_Name;
};

int main(int argc, const char* argv[]) {
	Entity entity(String("Cherno"));
	entity.PrintName();

	return 0;
}
//输出结果：
//Created!
//Copied!
//Cherno

#endif 





// 箭头操作符 和逆向引用 p46
// 常量引用 左值引用 常量左值引用
// https://zhuanlan.zhihu.com/p/557737070?utm_id=0
// move 函数 语义移动

/*

int a = 10;
const int& b = a; 常量引用b
*/
#if 0
#include <iostream>
#include <vector> //动态数组 
using namespace std;


class String {

public:
	String() = default;//构造函数
	String(const char* string) {
		// 常量引用和右值引用也可以，但是指针会方便一点
		printf("Created!\n");

	}



};


class enti {
public:
	void print() const { cout << "Hello World!" << endl; }
};

struct MyStruct
{
	float x, y, z;
};

ostream& operator<<(ostream& stream, const MyStruct& vv) {
	stream << vv.x << "," << vv.y << "," << vv.z << endl;
	return stream;
}


void conc(const int&& aa) {

	cout << "aa = " << aa << endl;
}

// 右值引用
void conc(int& aa) {

	cout << "aa = " << aa << endl;
}



// int& getVar() {
int& getVar() {
	// return 10;
	static int val = 10;
	return val;
}

int main()
{
	vector<MyStruct> ax;
	ax.push_back({ 1,2,3 });
	ax.push_back({ 14,125,63 });
	for (MyStruct& a : ax)
		cout << a << endl;
	enti e;
	e.print();

	enti* ptr = &e;
	enti& en = *ptr;
	(*ptr).print();
	en.print();
	ptr->print();// 箭头操作符 

	int a = 9; // 0x0000008748DAFB74   09 00 00 00
	int* p;//
	p = &a;
	// p的地址是&p 0x0000008748DAFB98 ,内容p 0x0000008748DAFB74  , *p=09
	// 
	int& p1 = *p;//int& p1 = 9; = int a = 9;
	// &p1 0x0000008748DAFB74     09 00 00 00
	// p1 = 9

	int* axx = new int;
	*axx = 5;

	int aar[5];
	int ix = getVar();
	getVar() = 99; //干了什么？

	int& qq = a;//因为qq的定义 是 int& 也就是 左值引用 类型。
	// 所以只能给左值 	int& qqq = 999;报错
	// 
	conc(a);
	conc(99); // 相当于把int 转成 const 常量引用兼容临时右值 左值引用
	std::cin.get();
}

#endif 


// const
// https://www.bilibili.com/video/BV1oD4y1h7S3
#if 0
#include <iostream>
using namespace std;

class myen {
public:
	mutable int x;
	int y;
	int getx() const { //mutable x 可以修改 x= 11； 
		//1、作于域内，不可以修改函数成员
		//2、在外可以被const myen& a,a.getx调用
		x = 11;
		return x;
	}
};


class student {
private:
	string name;
	int age;
public:
	student()
		:name("Unkonw"), age(99) //初始化列表 
	{
		// name = "Unkonw";
		// age = 99;
	}


};

void fune(const myen& a) {
	cout << a.getx() << endl;
}

int main()
{
	cout << "myConst-----------------";
	myen en1;
	en1.x = 99;
	en1.y = 12;
	cout << en1.x << en1.y << endl;
	fune(en1);
	std::cin.get();
}

#endif 


// P33
#if 0
#include <iostream>
using namespace std;


int main()
{
	const char* name = "HHH";
	// name[0] = "P";
	char name2[4] = { 'H','H','H','\0' };
	cout << name2 << endl;

	int b = 99;
	const int* a = new int;
	// *a = 2; 不能改变*a，但是可以改变a指向的内存地址
	// a = &b; 可以

	int* const a1 = new int;
	// *a1 = 2; 可以
	// a1 = &b; 不可以
	std::cin.get();
}

#endif 



// 数组 指针内存地址操作 P31
#if 0
#include <iostream>
//using namespace std;

int main()
{
	int exam[5];
	int* ptr = exam;
	for (int i = 0; i < 5; i++) {
		exam[i] = 2;
	}
	exam[2] = 5;
	*(ptr + 2) = 6;//exam[0+2]=6;
	*((char*)ptr + 8) = 6;//char 一个字节
	exam[0] = 9;
	std::cout << " exam[0] =  " << exam[0] << std::endl;
	*((char*)ptr + 1) = 3;
	std::cout << " exam[0] =  " << exam[0] << std::endl;
	std::cin.get();
}

#endif 




#if 0
#include <iostream>
//using namespace std; {}

enum Enx : int
{
	A = 1, B = 2, C = 3
};

int main()
{
	Enx varx = A;
	std::cin.get();
}

#endif 

// C++基础 改用 https://www.bilibili.com/video/BV1oD4y1h7S3 good

// log static link 
#if 0
#include <iostream>
//using namespace std;
void logtk(const char* msg);


// static 不会link 其他文件
// static int sVar = 9;
//
//extern int sVar;

class Log {

public:


	/*
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
	*/
	enum  level :int
	{
		// Error = 0, Warning = 1, Info = 2
		levelError = 0, levelWarning = 1, levelInfo = 2
	};


private:
	level m_LogLevel = levelInfo;
public:
	void SetLevel(level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message) {
		// if(m_LogLevel >= LogLevelError)
		//if(m_LogLevel >= Error)
		if (m_LogLevel >= levelError)
			std::cout << "[Error]: " << message << std::endl;
	}

	void Warn(const char* message) {
		if (m_LogLevel >= levelWarning)
			std::cout << "[Warn]: " << message << std::endl;
	}

	void Info(const char* message) {
		if (m_LogLevel >= levelInfo)
			std::cout << "[Info]: " << message << std::endl;
	}

};

static void linktest() {
	logtk("nihao");
}

//虚函数 

/*
claee p11{
   //virtual + 函数
   virtual void GetName(){
	   .....
   }
}

class p22{
	void GetName() override {return m_Name;}
	//C++11新标准允许给被重写的函数用"override"关键字标记,增强代码可读性。
}

*/



void func1() {
	// 局部静态
	// 生命周期是整个程序
	// 但是只能限制在局部作用域
	// 
	static int i = 0;
	i++;
	std::cout << i << std::endl;

}

int main()
{
	Log log;
	//log.SetLevel(Log::Error); Error = 0, Warning = 1, Info = 2
	// 有个函数也叫Error
	log.SetLevel(Log::levelError);
	log.Warn("Hello!");
	log.Error("Hello!");
	log.Info("Hello!");
	//logtk("nihao");
	//linktest();
	//std::cout << "sVar = " << sVar << std::endl;

	func1();
	func1();
	func1();
	func1(); //1\2\3\4

	std::cin.get();
}

#endif 



#if 0
#include <iostream>
//using namespace std;

#define struct class //类和结构体区别没有


class Player
{
public:

	int x;
	int y;
	void Move(int xa, int ya) {
		x += xa;
		y += ya;

	}
};

int main()
{
	Player p1;
	p1.Move(1, -1);
	std::cin.get();
}

#endif 



#if 0
#include <iostream>
using namespace std;
int main()
{
	// 调试-窗口-内存1 char 1个字节 两个16进制数子 对应一个字节
	// 
	char a = 65;
	cout << a << endl;
	//float var1 = 5.5;
	float var1 = 5.5f; //浮点4type，双精度8type
	double var2 = 5.2;
	char* buffer = new char[8];
	memset(buffer, 0, 8);//0 每个字节内容

	char** ptr = &buffer;
	delete[] buffer;
	std::cin.get();
	//return 0;
}

#endif 



// https://www.bilibili.com/video/BV1JT4y1Z7q3
// C++ 基础
// 改用 https://www.bilibili.com/video/BV1oD4y1h7S3 good
// 
#if 0
#include <iostream>
using namespace std;

#define dd 12

int main()
{
	int a = 1;
	int b{ 2 };
	const int c = 13;
	int const c1 = 15;
	cout << sizeof(a) << endl;

	int a1{ 500 };
	//long long a1{ 500 };
	unsigned b1{ 1000 };
	cout << (a1 - b1) << endl;
	cout << (int)(a1 - b1) << endl;

	// 字符的本质是数子
	//char wchat_t  char16_t char32_t 16 32 常用
	setlocale(LC_ALL, "chs");//输出中文
	std::wcout << (wchar_t)L'午' << endl;
	char16_t char16(u'A');//小u utf-16
	char32_t char32(U'A');//大U utf-32
	cout << (char)65 << endl; //A
	cout << 65 << endl; //65
	cout << char16 << endl;
	cout << char32 << endl;



	return 0;
}

#endif 




// 语义移动 右值引用
// 将亡值 
// https://www.bilibili.com/video/BV1Vq4y1K7ut 说法并不全对
#if 0
#include <iostream>
using namespace std;

class buffer {
};

buffer getbuffer() {
	buffer buf;
	cout << "&buf 地址" << &buf << endl;
	//cout << "buf =" << &buf << endl;
	return buf;
}

// --------------
void setbuffer(const buffer& buf) {
	cout << " setbuffer &buf 地址" << &buf << endl;
	cout << " setbuffer buf =" << &buf << endl;
}

int main()
{
	std::cout << "hello world" << std::endl;
	buffer buf1 = getbuffer(); //buf在拷贝给buf1，就没了
	cout << "main &buf 地址" << &buf1 << endl;
	setbuffer(buf1);
	cout << "-----------------------------------------------------" << endl;
	const buffer& buf2 = getbuffer();
	setbuffer(buf2);
	setbuffer(getbuffer());
	//const buffer & buf = getbuffer();
	//setbuffer(buf);
	//setbuffer(getbuffer()); //为什么加一个const 就不会报错
	return 0;
}

#endif 

// void* 
// https://www.jb51.net/program/286186150.htm#_lab2_1_3
// 可以使用void指针作为函数返回值，以便返回任何类型的数据或对象。
#if 0
#include <iostream>
using namespace std;

void* func(void* pArgs) {
	return pArgs;
}

int main() {
	int a = 5;
	int* p1 = &a;
	cout << &a << endl;
	cout << func(p1) << endl;
	return 0;
}


#endif




#if 0
#include <iostream>
using namespace std;


// 动态内存分配
// new-堆内存， 变量-栈内存
// int[] a = ***, a 栈内存，***在堆内存
// 关键字 new delete
//  https://blog.csdn.net/qq_21379779/article/details/128695080
// 栈内存 分配空间固定 不可变
// 指针 保存的 变量地址，是堆内存
// https://zhuanlan.zhihu.com/p/604965612


// 结构体 运算符重载


struct myVexctor
{
	int x;
	int y;
};

myVexctor operator * (int a, myVexctor b)
{
	myVexctor r;
	r.x = a * b.x;
	r.y = a * b.y;
	return r;
}
// myVexctor t1,t2;
// t1 = 999 * t2;



class Test {
public:
	Test() {
		mx = 0;
		my = 0;
	};
	Test(int a, int b) {
		mx = a;
		my = b;
	};

	// Test operator+(int a,const Test& another，) {}
	// 类的运算符重构接受的变量，只能一个？
	// https://blog.csdn.net/qq_44771627/article/details/122563302
	// 友元类内
	// 全局--运算符重载函数

	// 拷贝构造函数
	Test(const Test& another)
	{
		cout << "拷贝构造函数" << endl;
		mx = another.mx;
		my = another.my;
	}

	// Test t1(99,88);
	// Test t2 = t1; //拷贝构造函数
	// Test t3; t3 = t1; // 运算符，不是拷贝构造函数；



private:
	int mx;
	int my;
};


// 模板函数
template<class ta>
ta minValue(ta a, ta b) {
	return a + b;
}

template<class ta, class tb>
ta minValue2(ta a, tb b) {
	return (ta)(a + b);
}

// 内联函数 -- 内联展开 -- 效率更高 
inline void numChan(int x, int y) {
	x = 12;
	y = 14;
}


//1、引用 - 效率高
//当实参内存大，如果不希望，改变实参，可以用const 修改符。
// int myMan = 99 ; fu(myMan) myMan-实参
void fu(int& a) {
	a = 99;
}

void fuu(const int& a) {
	// a = 99; //报错
}

//2、地址传递
void fu2(int* p1, int* p2) {
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//值传递
void fu3(int x, int y) {

}



int main() {
	int xa = 110;
	cout << "xa 变量的地址： " << &xa << endl; //0x605F0E
	cout << " * (&xa) = " << *(&xa) << endl; // 110

	int* p;
	int ma = 999;
	p = &ma; // 在指针变量中存储 var 的地址
	cout << "ma的值：" << ma << endl;
	cout << "ma 变量的地址： " << &ma << endl; // 假设 0x168fx1
	cout << "指针p 存储（&ma）的地址,p = " << p << endl;
	cout << "指针p 存储的地址,上的值, *p = " << *p << endl;
	cout << "指向，变量（指针p）的地址(类似&ma), &p = " << &p << endl;
	//  000000472D93F738

	// https://www.bilibili.com/video/BV1kW411Y76d
	int* p1;
	p1 = new int;
	*p1 = 99;
	cout << "\n p1 = " << p1 << endl; //  输出：000002C1764D9510
	cout << "*p1 = " << *p1 << endl; // 99
	cout << "&p1 = " << &p1 << "\n" << endl;// new 输出：000000ED2C8FF908
	//  000000472D93F738 &p 不变；
	// new int 等同于 int a;
	delete p1;//释放new int 的内存块
	cout << "\n p1 = " << p1 << endl; // 输出：0000000000008123
	// cout << "*p1 = " << *p1 << endl; // 99
	cout << "&p1 = " << &p1 << "\n" << endl;// new  输出：000000ED2C8FF908


	// 现在想改变  0x168fx1 存储的值
	// 1、
	ma = 88;
	cout << "ma的值：" << ma << endl;
	// 2、
	*p = 66;
	cout << "ma的值：" << ma << endl;

	int a1 = 99;
	int a2 = 88;
	numChan(a1, a2);
	cout << "a1的值：" << a1 << endl;
	cout << "a2的值：" << a2 << endl;

	try {
		if (a1 > 100) throw 200; //如果a1>200 就抛出错误 200
		if (a1 < 10) throw 11;
		throw a1 / 3;
		throw "hello";// 字符串
	}
	catch (int result) {
		cout << "Result is:" << result << endl;
	}
	catch (char* s) {// throw "hello";// 字符串
		cout << "Result is:" << s << endl;
	}
	catch (...) { // ... 所有情况
		cout << "其他异常情况都在这里" << endl;
	}


	int aa = 3;
	double bb = 4.33;
	cout << "aa+ bb = " << minValue2(aa, bb) << endl;

	//--------------------
	return 0;
}



#endif



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