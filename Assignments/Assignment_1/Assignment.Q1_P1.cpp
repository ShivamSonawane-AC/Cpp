/* Requirements:
Store the reading as double, derive a status code as int using if-else
Use switch on the status code to print the action
Use the ternary operator to print Above Average or Below Average relative to 25°C (normal
operating temperature)
Print the temperature in Fahrenheit as well: F = (C × 9 / 5) + 32  */

#include <iostream>
using namespace std;

int main1() {

	double C = 47.3 , F;

	F = (C * 9/5) + 32;

	cout<<"Temp :"<<C<<"°C  / "<<F<<" °F"<<endl;

	int statusCode;

	if(C<0){
		cout<<"Status : SENSOR_ERROR"<<endl;
		statusCode = -1;
	}
	else if(C>0 && C<29){
		cout<<"Status : NORMAL"<<endl;
		statusCode = 0;
	}
	else if(C>30 && C<44){
		cout<<"Status : WARNING"<<endl;
		statusCode = 1;
	}
	else if(C>45 && C<59){
		cout<<"Status : CRITICAL"<<endl;
		statusCode = 2;
		}
	else {
		cout<<"Status : SHUTDOWN"<<endl;
		statusCode = 3;
	}

		switch(statusCode){
		case -1:
			cout<<"Action : Sensor fault — check wiring"<<endl;
			break;
		case 0:
			cout<<"Action : No action required"<<endl;
			break;
		case 1:
			cout<<"Action : Alert sent to supervisor"<<endl;
			break;
		case 2:
			cout<<"Action : Cooling system triggered"<<endl;
			break;
		case 3:
			cout<<"Action : Emergency shutdown initiated"<<endl;
			break;
		default :
			cout<<"BLASTT!!";

	}

		string abc = (C>25)?"Above Avg":"Below Avg";
		cout<<"Reading : "<<abc<<endl;

	return 0;
}
