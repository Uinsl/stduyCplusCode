#if 1
#include <iostream>
using namespace std;
#define wait std::cin.get();

#include "myVector.h"
#include "myArray.h"


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

	myVector<int> obj;

	
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