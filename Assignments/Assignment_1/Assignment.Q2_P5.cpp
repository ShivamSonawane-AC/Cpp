/*	In main(), set home position as (0.0, 0.0) and safe-zone radius as 50.0 units.
Test with 3 waypoints of your choice. For each waypoint print its distance from home
and whether it is inside the safe zone.  */

#include<iostream>
#include<cmath>
using namespace std;

inline double distanceBetween(double x1, double y1, double x2, double y2){
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

inline double toRadians(double degrees){
	return degrees * (M_PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal){
	if(value < minVal) return minVal;
	if(value > maxVal) return maxVal;
	return value;
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){
	double dist = distanceBetween(x, y, cx, cy);
	return dist <= radius;
}

int main(){

	double homeX = 0.0, homeY = 0.0;
	double radius = 50.0;

	double waypoints[3][2] = { {20.0, 30.0}, {45.0, 45.0}, {60.0, 10.0} };

	for(int i=0;i<3;i++){
		double x = waypoints[i][0];
		double y = waypoints[i][1];

		double dist = distanceBetween(x, y, homeX, homeY);
		bool safe = isInSafeZone(x, y, homeX, homeY, radius);

		cout<<"Waypoint "<<i+1<<" ("<<x<<", "<<y<<") -> Distance : "<<dist<<" units, ";
		cout<<(safe ? "Inside Safe Zone" : "Outside Safe Zone")<<endl;
	}

	return 0;
}
