/*	Rule: No arr[i] inside any of these functions. Use *ptr, *(ptr + i), or ptr++ only.
Test signal: {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1}  */

#include<iostream>
#include<cmath>
using namespace std;

double computeRMS(double* signal, int n){
	double sum = 0;
	for(int i=0;i<n;i++){
		sum += (*(signal+i)) * (*(signal+i));
	}
	return sqrt(sum/n);
}

void normalise(double* signal, int n){
	double maxVal = fabs(*signal);
	for(int i=0;i<n;i++){
		if(fabs(*(signal+i)) > maxVal){
			maxVal = fabs(*(signal+i));
		}
	}
	for(int i=0;i<n;i++){
		*(signal+i) = *(signal+i) / maxVal;
	}
}

int countZeroCrossings(double* signal, int n){
	int count = 0;
	double* ptr = signal;
	for(int i=0;i<n-1;i++){
		if((*ptr) * (*(ptr+1)) < 0){
			count += 1;
		}
		ptr++;
	}
	return count;
}

void applyGain(double* signal, int n, double gainFactor){
	for(int i=0;i<n;i++){
		*(signal+i) = *(signal+i) * gainFactor;
	}
}

int main6(){

	double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
	int n = 7;

	cout<<"Before : ";
	for(int i=0;i<n;i++){
		cout<<signal[i]<<" ";
	}
	cout<<endl;

	double rms = computeRMS(signal, n);
	int zeroCross = countZeroCrossings(signal, n);

	normalise(signal, n);

	cout<<"After normalise : ";
	for(int i=0;i<n;i++){
		cout<<signal[i]<<" ";
	}
	cout<<endl;

	applyGain(signal, n, 2.0);

	cout<<"After applyGain(2.0) : ";
	for(int i=0;i<n;i++){
		cout<<signal[i]<<" ";
	}
	cout<<endl;

	cout<<"RMS : "<<rms<<endl;
	cout<<"Zero Crossings : "<<zeroCross<<endl;

	return 0;
}
