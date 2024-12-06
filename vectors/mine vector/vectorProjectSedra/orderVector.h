#pragma once
#include<iostream>
#include"vector.h"
using namespace std;
//we need to override insertAt&pushPack 
//in orderVector the vector is ordered ascending 
//binary searche is way faster!!
 

template<class t>
class orderVector :public myVector<t> {
public:
	orderVector(int size = 100);
	void insertOrdered(const t& item);//finding the best location then insert the value
	virtual void insertAt(int loc, const t& nValue);
	virtual void pushPack(const t& nValue);
	int binarySearche(const t& nValue);//a faster searching way
};



template<class t>
orderVector <t>::orderVector(int size): myVector<t>(size){
}

template<class t>
void orderVector<t>::insertOrdered(const t& item) {
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
			if (this->list[mid] == item) {
				cerr << "the given value is alrady exicest,you cant do duplications!" << endl;
				found = true;
			}
			else if (this->list[mid] < item) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		if (this->list[mid] < item)mid++;
		myVector<t>::insertAt(mid, item);
	}
}
template<class t>
void orderVector<t>::insertAt(int loc, const t& nValue) {
	insertOrdered(nValue);
}

template<class t>
void orderVector<t>::pushPack(const t& nValue) {
	insertOrdered(nValue);
}

template<class t>
int orderVector<t>::binarySearche(const t& item) {
	int first = 0;
	int last = this->length - 1;
	int mid;
	bool found = false;
	while (first <= last && !found) {
		mid = (first + last) / 2;
		if (this->list[mid] == item) {
			found = true;
		}
		else if (this->list[mid] < item) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	if (found)return mid;
	else return -1;
}