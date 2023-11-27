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
		realloc(m_data, sizeof(T) * m_memSize); //sizeof(int) 32λ 4�ֽڣ�64λ 8�ֽڡ�
		//m_data[0] = data;
		//m_size++;
		*(m_data + m_size) = 0;
		//m_size++;
	}


private:
	// ������һ����š�
	T* m_data;//��ʼָ��
	size_t m_size;//�±�
	size_t m_memSize;//�ֽڸ���
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

*/


