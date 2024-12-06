#include "MyVectorT.h"
#include "OrderedMyVectorT.h"
#include <iostream>

using namespace std;


int main() {
	int x;
	MyVector<int>CC(5);
	CC.insertAt(0, 10);
	CC.insertAt(0, 15);
	CC.print();
	
	
	cout << "length = " << CC.listSize() << "   maxSize = " << CC.maxMyVectorSize() << endl;

	MyVector<int> A(3);

	cout << "length = "<<A.listSize() << "   maxSize = " << A.maxMyVectorSize() << endl;
	A.push_back(10);
	A.push_back(20);
	A.push_back(30);
	A.print();

	for(int i=0; i<A.listSize(); i++) cout <<"At "<<i<<" : "<< A[i] << endl;
	cout << "length = " << A.listSize() << "   maxSize = " << A.maxMyVectorSize() << endl;
	A.insertAt(0, 70);
	cout << "length = " << A.listSize() << "   maxSize = " << A.maxMyVectorSize() << endl;
	
	

	A.print();
	A.shrink_to_fit();
	cout << "length = " << A.listSize() << "   maxSize = " << A.maxMyVectorSize() << endl;
	A.print();
	

	MyVector<int> B(3);

	B.push_back(100);
	B.push_back(200);
	B.push_back(300);
	MyVector<int> C(3);

	C = A + B;
	cout << "length = " << C.listSize() << "   maxSize = " << C.maxMyVectorSize() << endl;
	C.insertAt(2, 1000);
	cout << "length = " << C.listSize() << "   maxSize = " << C.maxMyVectorSize() << endl;
	C.print();

	OrderedMyVector<string> ord(2);
	ord.insertAt(0,"Hassan");
	ord.insertAt(10,"Amal");
	ord.insertAt(5,"Mohammed");
	ord.insertOrd("Fathi");
	ord.push_back("Ammar");
	cout << "length = " << ord.listSize() << "   maxSize = " << ord.maxMyVectorSize() << endl;
	ord.print();
	ord.removeAt(1);
	ord.print();
	cout<<ord.binarySearch("Hassan");
	return 0;
}