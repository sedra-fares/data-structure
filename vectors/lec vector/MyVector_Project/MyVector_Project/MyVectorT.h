#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class MyVector {
public:
	MyVector(int size = 100);
	MyVector(const MyVector<T>& otherMyVector);
	~MyVector();
	void operator=(const MyVector<T>&);
	MyVector<T> operator+(const MyVector& M);
	T operator[](int i);

	bool  isEmpty() const;
	bool  isFull() const;
	int   listSize() const;   //length
	int   maxMyVectorSize() const;      //maxsize
	void  print() const;
	bool  isItemAtEqual(int location, const T& item) const;
	virtual void insertAt(int location, const T& insertItem);    //
	virtual void push_back(const T& insertItem);
	void removeAt(int location);
	void remove(const T& removeItem);
	void retrieveAt(int location, T& retItem) const;
	void replaceAt(int location, const T& repItem);
	void clearMyVector();
	int seqSearch(const T& item) const;
	void shrink_to_fit();


protected:
	T* list;
	int length;
	int maxSize;
private:
	void alloc_new();
	
};


template <class T>
bool MyVector<T>::isEmpty() const {
	return (length == 0);
}

template <class T>
bool MyVector<T>::isFull() const {
	return (length == maxSize);
}

template <class T>
int MyVector<T>::listSize() const {
	return length;
}

template <class T>
int MyVector<T>::maxMyVectorSize() const {
	return maxSize;
}

template <class T>
void MyVector<T>::print() const {
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}

template <class T>
bool MyVector<T>::isItemAtEqual(int location, const T& item) const {
	return(list[location] == item);
}

template <class T>
void MyVector<T>::insertAt(int location, const T& insertItem) {
	if (location < 0 || location > maxSize)
		cerr << "The position of the item to be inserted " << "is out of range" << endl;
	else {
		if (isFull()) alloc_new();

		for (int i = length; i > location; i--)
			list[i] = list[i - 1];
		list[location] = insertItem;
		length++;
	}
}

template <class T>
void MyVector<T>::push_back(const T& insertItem) {
	if (isFull()) alloc_new();

	list[length] = insertItem;
	length++;

}

template <class T>
void MyVector<T>::removeAt(int location) {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed " << "is out of range" << endl;
	else {
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
}

template <class T>
void MyVector<T>::retrieveAt(int location, T& retItem) const {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is " << "out of range." << endl;
	else
		retItem = list[location];
}

template <class T>
void MyVector<T>::replaceAt(int location, const T& repItem) {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is " << "out of range." << endl;
	else
		list[location] = repItem;
}

template <class T>
void MyVector<T>::clearMyVector() {
	length = 0;
}

template <class T>
MyVector<T>::MyVector(int size) {
	if (size < 0) {
		cerr << "The array size must be positive. Creating " << "an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new T[maxSize];
	assert(list != NULL);
}

template <class T>
MyVector<T>::~MyVector() {
	delete[] list;
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& otherMyVector) {
	maxSize = otherMyVector.maxSize;
	length = otherMyVector.length;
	list = new T[maxSize];
	assert(list != NULL);
	for (int j = 0; j < length; j++)
		list[j] = otherMyVector.list[j];
}

template <class T>
void MyVector<T>::alloc_new()
{
	maxSize *= 2;
	T* B = new T[maxSize];
	for (int i = 0; i < length; i++)
		B[i] = list[i];

	delete[]list;
	list = B;
}

template <class T>
void MyVector<T>::shrink_to_fit()
{
	maxSize = length;
	T* B = new T[maxSize];
	for (int i = 0; i < length; i++)
		B[i] = list[i];

	delete[]list;
	list = B;
}

template <class T>
void MyVector<T>::operator=(const MyVector<T>& otherMyVector) {
	if (this != &otherMyVector) {
		delete[] list;
		maxSize = otherMyVector.maxSize;
		length = otherMyVector.length;
		list = new T[maxSize];
		assert(list != NULL);
		for (int i = 0; i < length; i++)
			list[i] = otherMyVector.list[i];
	}

}

template <class T>
T MyVector<T>::operator[](int i) { return list[i]; }

template <class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& M)
{
	MyVector <T> C; int i;
	delete[]C.list;
	C.maxSize = maxSize + M.maxSize;
	C.length = length + M.length;
	C.list= new T[C.maxSize];
	for (i = 0; i < length; i++)
		C.list[i] = list[i];
	for (int j = 0; j < M.length; j++, i++)
		C.list[i] = M.list[j];

	return C;

}


template <class T>
int MyVector<T>::seqSearch(const T& item) const {
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++)
		if (list[loc] == item) {
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
}

template <class T>
void MyVector<T>::remove(const T& removeItem) {
	int loc;
	if (isEmpty())
		cerr << "Cannot delete from an empty list." << endl;
	else {
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
}


