#pragma once
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

	const T* Data() const {
		return m_data;
	}

	/*
	T& operator[](int index) const {
		cout << "T& [] const" << endl;
		return m_data[index];
	}*/

	int& mmx(int index) const {
		// const �޶������εķ��ص�ֵ���ض���cosnt����?��const��������
		// ���ԣ�t& => const ʱ��t ����Ϊconst
		// https://blog.csdn.net/HackCyberX/article/details/133381523
		cout << "mmx" << endl;
		return m_data[index];
	}

private:
	T m_data[S];
};