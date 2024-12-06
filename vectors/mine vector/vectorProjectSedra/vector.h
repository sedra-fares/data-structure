#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class t>
class myVector {
public:

	


	myVector(int size = 100);
	~myVector();
	myVector(const myVector<t>& copyConst);

	//overloading »ÿÌŒ
	void operator=(const myVector<t>& item);
	myVector<t> operator+(const myVector<t>& M);//concat tow vectors
	t operator[](int i);

	//methodes
	bool isEmpty()const;//check if the list is empty
	bool isFull()const;//check if the list is full,if yes allocate new list(make alloc methode)
	int listSize()const;//returns nuber of items in the list(length)
	int maxVectorSize()const;//returns the max size of the list
	void printVector()const;//prints all the vectors list elemntes
	bool isItemEquel(int loc, const t& item)const;//check if the given value is the same in the given location
	void allocVector();//allocate new memorey when the list is full
	virtual void insertAt(int loc, const t& nValue);//insert the given value in a given location
	virtual void pushPack(const t& nValue);//insert the given value at the end of the vector
	void removeAt(int loc);//remove the value of the given location
	void remove(const t& nValue);//remove the given value from the vector
	void retriveAt(int loc, t& store)const;//retrive the value of the given location and store it in the given variable
	void replaceAt(int loc, const t& nValue);//replace the old list value withe the new given one
	void clearMyVector();//delete all the vectors values(length=0)
	int seqSearch(const t& nValue)const;//serach about the given value and return its index(location)
	void shrinkToFit();//make new list with max size=length and delet the last list



protected:
	int length;
	int maxSize;
	t* list;


};
template<class t>
myVector<t>::myVector(int size ) {
	if (size < 0) {
		cerr << "the size cant be negative value, will allocate size 100";
		maxSize = 100;
		
	}else
	maxSize = size;
	length = 0;
	list = new t[maxSize];
}

template<class t>
myVector<t>::~myVector() {
	delete[]list;
}

template<class t>
myVector<t>::myVector(const myVector<t>& copyConst) {
	maxSize = copyConst.maxSize;
	length = copyConst.length;
	list = new t[maxSize];
	for (int i = 0; i < copyConst.length; i++) {
		list[i] = copyConst.list[i];
	}
}

template<class t>
bool myVector<t>::isEmpty()const {
	return(length == 0);
}
template<class t>
bool myVector<t>::isFull()const {
	return(maxSize == length);
	
}
template<class t>
int myVector<t>::listSize()const {
	return length;
}
template<class t>
int myVector<t>::maxVectorSize()const {
	return maxSize;
}
template<class t>
void myVector<t>::printVector()const {
	for (int i = 0; i < length; i++) {
		cout << "vector item number " << i + 1 << " is: " << list[i]<<endl;
	}
}
template<class t>
bool myVector<t>::isItemEquel(int loc, const t& item)const {

	return(list[loc] == item);
}

template<class t>
void myVector<t>::allocVector() {
	
		maxSize *= 2;
		t* b = new t[maxSize];
		for (int i = 0; i < length; i++) {
			b[i] = list[i];
		}
		delete[]list;
		list = b;

	
}
template<class t>
void myVector<t>::insertAt(int loc, const t& nValue) {
	if (isFull()) {
		allocVector();
	}
	for (int i = length; i > loc;i--) {
		list[i] = list[i - 1];
	}
	list[loc] = nValue;
	length++;
}
template<class t>
void myVector<t>::pushPack(const t& nValue) {
	if (isFull()) {
		allocVector();
	}
	list[length] = nValue;
	length++;

}

template <class t>
void myVector <t>::operator=(const myVector<t>& otherMyVector) {
	if (this != &otherMyVector) {
		delete[] list;
		maxSize = otherMyVector.maxSize;
		length = otherMyVector.length;
		list = new t[maxSize];
		assert(list != NULL);
		for (int i = 0; i < length; i++)
			list[i] = otherMyVector.list[i];
	}

}












template<class t>
void myVector<t>::removeAt(int loc) {
	
	for (int i = loc; i < length-1; i++) {
		list[i] = list[i + 1];
	}
	length--;
}
template<class t>
void myVector<t>::remove(const t& nValue) {
	int loc = -1;
	for (int i = 0; i < length; i++) {
		if (list[i] == nValue) { list[i] = NULL; loc = i; }
	}
	if (loc != -1) {
		for (int i = loc; i < length - 1; i++) {
			list[i] = list[i + 1];
		}
		length--;
	}
	else cout << "the value is not founed in the vector" << endl;
}
template<class t>
void myVector<t>::retriveAt(int loc, t& store)const {
	if (loc > 0 || loc < length) {
		store = list[loc];
	}
	else cerr << "there is no matching location in the vector" << endl;
}
template<class t>
void myVector<t>::replaceAt(int loc, const t& nValue) {
	if (loc > 0 || loc < length) {
		list[loc] = nValue;

	}
	else cerr << "there is no matching location in the vector" << endl;
}
template<class t>
void myVector<t>::clearMyVector() {
	length = 0;
}

template<class t>
int myVector<t>::seqSearch(const t& nValue)const {
	int loc = -1;
	for (int i = 0; i < length; i++) {
		if (list[i] == nValue) { loc = i; }
	}
	if (loc == -1) {
		cerr << "the value no found" << endl;
	}
	return loc;
}
template<class t>
void myVector<t>::shrinkToFit() {
	maxSize =length;
	t* b = new t[maxSize];
	for (int i = 0; i < length; i++) {
		b[i] = list[i];
	}
	delete[]list;
	list = b;

}

template <class t>
myVector<t> myVector<t>::operator+(const myVector<t>& M)
{
	myVector <t> C; int i;
	delete[]C.list;
	C.maxSize = maxSize + M.maxSize;
	C.length = length + M.length;
	C.list = new t[C.maxSize];
	for (i = 0; i < length; i++)
		C.list[i] = list[i];
	for (int j = 0; j < M.length; j++, i++)
		C.list[i] = M.list[j];

	return C;

}
template <class t>
t myVector<t>::operator[](int i) { return list[i]; }

//finalllllly DONE