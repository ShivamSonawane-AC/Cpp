/*	Requirements:
1. Accept N from the user (1 ≤ N ≤ 100), then read N temperature values into an array
2. Print all valid readings — skip values below 0 (sensor error) using continue
3. Scan for the first reading at or above 45°C — print its index and stop scanning using break
4. Compute min, max, and average in one single loop pass
5. Count readings per category: Normal / Warning / Critical / Shutdown  */

#include<iostream>
#include<algorithm>
using namespace std;


int main2(){

	cout<<"Enter N :"<<endl;
	int n;
	int errorCount = 0;
	cin>>n;

	cout<<"Enter Array :"<<endl;
	double arr[100];

	for(int i=0; i<n;i++){
		cin>>arr[i];
	}


	cout<<"Reading Entered: "<<n<<endl;
	cout<<"Valid readings : ";
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			errorCount+=1;
			continue;
		}
		cout<<arr[i]<<" ";
	}

	cout<<endl;

	cout<<"Skipped (errors) : "<<errorCount<<endl;

	for(int i=0;i<n;i++){
			if(arr[i]>=45){
				cout<<"First Critical : Index "<<i<<" -> "<<arr[i]<<endl;
				break;
			}
		}

	double minValue=arr[0], maxValue=arr[0], sum = 0, avg =0, countAvg = 0;

	for(int i=0; i<n; i++){

		if(arr[i] < 0){
			continue ;
		}
		minValue = min(minValue, arr[i]);
		maxValue = max(maxValue, arr[i]);

		sum += arr[i];
        countAvg += 1;
	}
		avg = sum/countAvg;


	cout<<"Min : "<<minValue<<"°C"<<"  "<<"Max :"<<maxValue<<"°C"<<" Avg : "<<avg<<"°C"<<endl;






	int Count = 0 , CountW = 0, CountC = 0, CountS = 0;

			for(int i=0;i<n;i++){
				if(arr[i]>0 && arr[i]<25){
				Count+=1;
				}
				else if(arr[i]>25 && arr[i]<45){
					CountW+=1;
				}

				else if(arr[i]>45 && arr[i]<100){
					CountC += 1;
				}
				else{
					CountS += 1;
				}
			}
			cout<<"Normal : "<<Count<<" ";
			cout<<"Warning :"<<CountW<<" ";
			cout<<"Critical :"<<CountC<<" ";
			cout<<"Shutdown :"<<CountS<<" ";
	return 0;
}
