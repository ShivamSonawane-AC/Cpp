/*	Requirements:
Declare regPtr1 as const int* pointing to statusReg — print its value; attempt a write and a
repoint, comment both out with error explanation
Declare regPtr2 as int* const pointing to controlReg — write a new value through it; attempt a
repoint, comment it out with explanation
Declare regPtr3 as const int* const pointing to statusReg — print its value; attempt both write
and repoint, comment both out with explanations  */

#include<iostream>
using namespace std;

int main7(){

	int statusReg = 0b10110001;
	int controlReg = 0b00000000;
	int dataReg = 0b11001010;

	const int* regPtr1 = &statusReg;
	cout<<"regPtr1 (statusReg) : "<<*regPtr1<<endl;
	// *regPtr1 = 5;      // ERROR : regPtr1 is pointer to const int, cant modify value thru it
	// regPtr1 = &dataReg;   // this is allowed actually, since only the value is const not pointer itself

	int* const regPtr2 = &controlReg;
	*regPtr2 = 0b00001111;
	cout<<"regPtr2 (controlReg) after write : "<<*regPtr2<<endl;
	// regPtr2 = &dataReg;   // ERROR : regPtr2 is const pointer, address is fixed once assigned, cant repoint

	const int* const regPtr3 = &statusReg;
	cout<<"regPtr3 (statusReg) : "<<*regPtr3<<endl;
	// *regPtr3 = 5;        // ERROR : value is const thru this pointer, cant write
	// regPtr3 = &dataReg;  // ERROR : pointer itself is const, cant repoint either

	return 0;
}
