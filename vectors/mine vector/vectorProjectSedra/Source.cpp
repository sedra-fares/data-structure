#include<iostream>
#include"vector.h"
#include"orderVector.h"

using namespace std;

int main() {

	int x;
	myVector<int>CC(5);
	CC.insertAt(0, 10);
	CC.insertAt(0, 15);
	CC.printVector();


	cout << "length = " << CC.listSize() << "   maxSize = " << CC.maxVectorSize() << endl;

	myVector<int> A(3);

	cout << "length = " << A.listSize() << "   maxSize = " << A.maxVectorSize() << endl;
	A.pushPack(10);
	A.pushPack(20);
	A.pushPack(30);
	A.printVector();

	for (int i = 0; i < A.listSize(); i++) cout << "At " << i << " : " << A[i] << endl;
	cout << "length = " << A.listSize() << "   maxSize = " << A.maxVectorSize() << endl;
	A.insertAt(0, 70);
	cout << "length = " << A.listSize() << "   maxSize = " << A.maxVectorSize() << endl;



	A.printVector();
	A.shrinkToFit();
	cout << "length = " << A.listSize() << "   maxSize = " << A.maxVectorSize() << endl;
	A.printVector();


	myVector<int> B(3);

	B.pushPack(100);
	B.pushPack(200);
	B.pushPack(300);
	myVector<int> C(3);

	C = A + B;
	cout << "length = " << C.listSize() << "   maxSize = " << C.maxVectorSize() << endl;
	C.insertAt(2, 1000);
	cout << "length = " << C.listSize() << "   maxSize = " << C.maxVectorSize() << endl;
	C.printVector();

	orderVector<string> ord(2);
	ord.insertAt(0, "Hassan");
	ord.insertAt(10, "Amal");
	ord.insertAt(5, "Mohammed");
	ord.insertOrdered("Fathi");
	ord.pushPack("Ammar");
	cout << "length = " << ord.listSize() << "   maxSize = " << ord.maxVectorSize() << endl;
	ord.printVector();
	ord.removeAt(1);
	ord.printVector();
	cout << ord.binarySearche("Hassan");
	return 0;


}