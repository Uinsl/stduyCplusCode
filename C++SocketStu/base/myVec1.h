#pragma once

using namespace std;
//#include <iostream>  
//#include <new>  

template <class T>
class MyVector {
public:
    T* data; // ָ��ָ���ַ
    int size;  //�����Ԫ�ظ���
    int capacity;  //�ڴ��С

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
        if (size == capacity) { //�жϵ�ǰ�洢�ĸ����Ƿ�Ҫ����������ڴ�
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

1��malloc
https://www.cnblogs.com/imreW/p/17061649.html
int* p;
p = malloc(sizeof(int));

2��calloc
http://www.manongjc.com/detail/31-gtpbxfovxtgwjrm.html
int *ptr;
ptr = (int *)calloc(5, sizeof(int));

3��realloc()
https://www.cnblogs.com/klchang/p/5719470.html
�� C ������ malloc��calloc��realloc ��free ������ʹ�÷��� ��
ͷ�ļ���stdlib.h
������void * realloc(void * p,int n);
���壺���·�����ϵ�voidָ��p��ָ�Ŀռ�Ϊn���ֽڣ�ͬʱ�Ḵ��ԭ�����ݵ��·���Ķ��ϴ洢�ռ䡣
ע�⣬��ԭ����voidָ��p�ڶ��ϵĿռ䲻����n���ֽڣ��򱣳ֲ��䡣
����ֵ��ͬmalloc() ����

ջֻ������������ʱ�������ֲ������ͺ���������
�ں�������ʱ���Զ��ͷ���ռ�õĴ洢�ռ䡣
�����ϵ��ڴ�ռ䲻���Զ��ͷţ�ֱ������free()�������Ż��ͷŶ��ϵĴ洢�ռ䡣

https://www.bilibili.com/video/BV1cN4y177nU



int* p1;
p1 = malloc(sizeof(int)*1);  // malloc ����ռ�
p1[0] = 999;

����1
// ����һ������Ŀռ�
int* p2;
p2 = malloc(sizeof(int)*1);

//ʹ��memcpy����p1���ݸ��Ƹ�p2

int arr1[10] = {1, 2, 3, 4, 5};
int arr2[10];
size_t n = 3; // ����ǰ3��Ԫ��
memcpy(arr2, arr1, n * sizeof(int)); //arr2�����ݽ���{1, 2, 3}��

data  = p2 ��


����2��
realloc����

int *arr1 = (int *)malloc(10 * 4);//10��int ��һ��int 4�ֽ�
for��int v in arr1��{
	v = 1 2 3 4 5 6 7 8 9 0
}

int* arr2;
arr2 = realloc(arr1, 10 * sizeof(int));	// ��arrָ����ڴ��Ĵ�С��Ϊ10�������Ŀռ䣬 arr1 ������Ҳ�ᱻ���Ƴ���

// realloc(arr1, 3 * sizeof(int));// ����1

// ʹ��arrָ����ڴ�������������...
free(arr); // �ͷ��ڴ��


����3 : ʹ��new �����ڴ�
T* arr3 = new int[size];
��arr1 �����ݸ��Ƶ� arr3
��mdata ָ��arr3


��C++�У����ڳ�ʼ�������ڴ�ĺ����У�

new �������ʹ�� new ��������Զ�̬�ط����ڴ沢��ʼ�����顣���磺
int* arr = new int[10]; // ����10���������ڴ�ռ䲢�Զ���ʼ��Ϊ0
����һ�� ��ȥ�����

calloc ������ʹ�� calloc ���������ڷ����ڴ��ͬʱ�����ʼ��Ϊ0�����磺
int* arr = (int*)calloc(10, sizeof(int)); // ����10���������ڴ�ռ䲢��ʼ��Ϊ0

ֱ�ӳ�ʼ�����ڶ�������ʱ������ֱ��ʹ�ó�ʼ���б�����ʼ������Ԫ�ء����磺
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ��ʼ������Ԫ��

calloc �� new ����
�ڴ���䷽ʽ��new������ͨ�����ù��캯������ʼ�����󣬶�calloc����ͨ�����ù��캯�����ڴ��ʼ��Ϊ0��

�������ͣ�new����������һ������ָ�룬��calloc��������һ��ָ���ѷ����ڴ��ָ�롣
��ˣ�ʹ��new������ʱ����Ҫ����ǿ������ת������ʹ��calloc����ʱ��Ҫ�����ص�ָ��ת��Ϊ�������͵�ָ�롣
�ڴ����ʧ��ʱ�ķ���ֵ������ڴ����ʧ�ܣ�new���������׳�һ���쳣����calloc����������NULL��

�ڴ��ͷţ�ʹ��new������ڴ���Ҫ�ڲ���ʹ��ʱ��ʽ���ͷţ��Ա����ڴ�й©��ʹ��calloc������ڴ����ʹ��free�����ͷš�


*/

/*

// ����һ��ģ���� MyVector�����Դ洢�������͵�Ԫ��
template <class T>
class MyVector {
private:
    // ��ǰ�����Ĵ�С����Ԫ�صĸ���
    int size;
    // ����������������ǰ������ڴ�ռ��С
    int capacity;
    // �洢Ԫ�صĶ�̬����
    T* data;

public:
    // ���캯������ʼ�������Ĵ�СΪ0������Ϊ2����ΪԪ����������ڴ�ռ�
    MyVector() {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

    // �����������ͷ�Ԫ��������ڴ�ռ�
    ~MyVector() {
        delete[] data;
    }

    // ���������һ��Ԫ�أ������ǰ��������������չ����������ԭ��Ԫ�ص��µ��ڴ�ռ�
    void push_back(T value) {
        if (size == capacity) {
            capacity *= 2;  // ��size�ﵽ��ǰcapacity����ʱ����capacity�����������ɸ����Ԫ��
            T* new_data = new T[capacity];  // �����µ��ڴ�ռ����洢Ԫ��
            for (int i = 0; i < size; i++) {  // ��ԭ��Ԫ�ظ��Ƶ��µ��ڴ�ռ���
                new_data[i] = data[i];
            }
            delete[] data;  // �ͷ�ԭ���ڴ�ռ�
            data = new_data;  // ��ָ�����ڴ�ռ��ָ�븳ֵ��data���Ա����������Ԫ��
        }
        data[size] = value;  // �ڵ�ǰ����δ��������£�����Ԫ����ӵ�data�����ĩβ��������size��ֵ
        size++;  // ����size��ֵ����ʾ������Ԫ�ص�����������һ��
    }

    // ��������ɾ�����һ��Ԫ�أ����ͷ���ռ�õ��ڴ�ռ�
    void pop_back() {
        if (size > 0) {  // ���������Ϊ�գ���size����0������ִ��pop_back����
            size--;  // ����size��ֵ����ʾ������Ԫ�ص�����������һ��
        }
    }

    // ͨ���������������е�Ԫ�أ��������Խ�����׳�һ���쳣��out_of_range��
    T& operator[](int index) {
        if (index < 0 || index >= size) {  // ��������Ƿ�����Ч��Χ�ڣ�0��size-1��
            throw std::out_of_range("Index out of range");  // ���������Ч��Χ�ڣ����׳�һ���쳣
        }
        return data[index];  // �����������Ч��Χ�ڣ��򷵻�data��������Ӧλ�õ�Ԫ�����ã�ָ�룩
    }

    // ����������Ԫ�ص�������size��ֵ��
    int size() {
        return size;  // ����size��ֵ��Ϊ������Ԫ�ص�������size��
    }
};









*/

