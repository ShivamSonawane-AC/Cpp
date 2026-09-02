/*	Requirements:
If arguments are missing, print a usage line and exit with code 1
Validate: warn < critical, 1 ≤ num_readings ≤ 500 — print a specific error and exit on failure
If valid, simulate num_readings temperature values using rand() % 70, classify each using the
provided thresholds, and print a category summary  */

#include<iostream>
#include<cstdlib>
using namespace std;

int main4(int argc, char* argv[]){

	if(argc < 4){
		cout<<"Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>"<<endl;
		cout<<"Error : Missing arguments."<<endl;
		return 1;
	}

	int warn = atoi(argv[1]);
	int critical = atoi(argv[2]);
	int numReadings = atoi(argv[3]);

	if(warn >= critical){
		cout<<"Error : warn_threshold must be less than critical_threshold."<<endl;
		return 1;
	}

	if(numReadings < 1 || numReadings > 500){
		cout<<"Error : num_readings must be between 1 and 500."<<endl;
		return 1;
	}

	cout<<"Config : Warn="<<warn<<"°C Critical="<<critical<<"°C Readings="<<numReadings<<endl;

	int Count = 0, CountW = 0, CountC = 0, CountS = 0;

	for(int i=0;i<numReadings;i++){
		int reading = rand() % 70;

		if(reading < warn){
			Count += 1;
		}
		else if(reading < critical){
			CountW += 1;
		}
		else if(reading < 60){
			CountC += 1;
		}
		else{
			CountS += 1;
		}
	}

	cout<<"Results : Normal:"<<Count<<" Warning:"<<CountW<<" Critical:"<<CountC<<" Shutdown:"<<CountS<<endl;

	return 0;
}
