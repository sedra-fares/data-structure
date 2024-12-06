#pragma once

#include <iostream>
#include <assert.h>
#include "MyVectorT.h"

using namespace std;

//override insertAt
//override push_back

template <class T>
class OrderedMyVector : public MyVector<T> {
public:
	OrderedMyVector(int size = 100);
	void insertOrd(const T& item);
	int binarySearch(const T& item) const;
	virtual void push_back(const T& insertItem);
	virtual void insertAt(int location, const T& insertItem);
};

template <class T>
void OrderedMyVector<T>::insertOrd(const T& item) {
	int first = 0;
	int last = this->length - 1;
	int mid;
	bool found = false;
	if (this->length == 0) {
		this->list[0] = item;
		this->length++;
	}
	else
	{
		while (first <= last && !found) {
			mid = (first + last) / 2;
			if (this->list[mid] == item)
				found = true;
			else if (this->list[mid] > item)  last = mid - 1;
			else first = mid + 1;
		}
		if (found)
			cerr << "The insert item is already in the list. " << "Duplicates are not allowed." << endl;
		else {
			if (this->list[mid] < item) mid++;
			MyVector<T>::insertAt(mid, item);
		}
	}
}

template <class T>
int OrderedMyVector<T>::binarySearch(const T& item) const {
	
	int first = 0;
	int last = this->length - 1;
	int mid;
	bool found = false;

	while (first <= last && !found) {
		mid = (first + last) / 2;
		if (this->list[mid] == item)
			found = true;
		else if (this->list[mid] > item)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found) return mid;
	else return -1;
}

template <class T>
OrderedMyVector<T>::OrderedMyVector(int size) : MyVector<T>(size) {
}

template <class T>
void OrderedMyVector<T>::push_back(const T& insertItem) {
	insertOrd(insertItem);
}

template <class T>
void OrderedMyVector<T>::insertAt(int location, const T& insertItem) {
	insertOrd(insertItem);
}
