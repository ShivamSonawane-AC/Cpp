/*	Requirements:
1. Read temperatures for all 9 rooms into a 2D array (rows = floors, columns = rooms)
2. Display the readings in a formatted table
3. Find and report the hottest room (floor and room number)
4. Find and report the floor with the highest average temperature
5. Count total rooms at or above the WARNING threshold (30°C)  */

#include<iostream>
using namespace std;

int main3(){

	double arr[3][3];
	cout<<"Enter Temperature for 3 Floors and 3 Rooms :"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}

	cout<<endl;
	cout<<"Room1  Room2  Room3"<<endl;
	for(int i=0;i<3;i++){
		cout<<"Floor "<<i+1<<" : ";
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}

	double hottest = arr[0][0], highestAvg = 0;
	int hotFloor = 0, hotRoom = 0, highestFloor = 0;
	int Count = 0;

	for(int i=0;i<3;i++){
		double sum = 0;
		for(int j=0;j<3;j++){
			if(arr[i][j] > hottest){
				hottest = arr[i][j];
				hotFloor = i;
				hotRoom = j;
			}
			if(arr[i][j] >= 30){
				Count += 1;
			}
			sum += arr[i][j];
		}
		double avg = sum/3;
		if(avg > highestAvg){
			highestAvg = avg;
			highestFloor = i;
		}
	}

	cout<<"Hottest Room : Floor "<<hotFloor+1<<", Room "<<hotRoom+1<<" -> "<<hottest<<"°C"<<endl;
	cout<<"Hottest Floor : Floor "<<highestFloor+1<<" (avg "<<highestAvg<<"°C)"<<endl;
	cout<<"Rooms at WARNING or above : "<<Count<<endl;

	return 0;
}
