/*	Requirements:
Write all three versions:
void resetSensorPairV1(int reading1, int reading2); // Original bug — Call by Value
void resetSensorPairV2(int& reading1, int& reading2); // Fix 1 — Call by Reference
void resetSensorPairV3(int* reading1, int* reading2); // Fix 2 — Call by Pointer
Call all three from main(). Print values before and after each call.  */

#include<iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}

void resetSensorPairV2(int& reading1, int& reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}

void resetSensorPairV3(int* reading1, int* reading2){
	int temp = *reading1;
	*reading1 = *reading2;
	*reading2 = temp;
}

int main5(){

	int A = 55, B = 12;

	cout<<"---- V1: Call by Value ---"<<endl;
	cout<<"Before : A="<<A<<" B="<<B<<endl;
	resetSensorPairV1(A, B);
	cout<<"After : A="<<A<<" B="<<B<<" <- values unchanged"<<endl;

	cout<<endl;

	cout<<"---- V2: Call by Reference ---"<<endl;
	cout<<"Before : A="<<A<<" B="<<B<<endl;
	resetSensorPairV2(A, B);
	cout<<"After : A="<<A<<" B="<<B<<" <- values swapped"<<endl;

	cout<<endl;

	cout<<"---- V3: Call by Pointer ---"<<endl;
	cout<<"Before : A="<<A<<" B="<<B<<endl;
	resetSensorPairV3(&A, &B);
	cout<<"After : A="<<A<<" B="<<B<<" <- values swapped back"<<endl;

	/* V1 doesn't work coz call by value makes a copy of reading1 & reading2
   so swap happens on the copy only, original A & B in main stay same.
   V2 works coz reference is like alias of original var.
   V3 works coz pointer holds address so *ptr changes original value directly . */

	return 0;
}
