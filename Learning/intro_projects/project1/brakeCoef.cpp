// Date:  11/14/2017
// Filename:  brakeCoef.cpp
// Program Description:
// This program purpose is to calculate the passenger shuttle's optimal braking
//coefficient given the initial velocity, air braking coefficient, and stopping
//distance. 

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main() {
	//declare variables that will be used as input for the program
		//breaking coefficient 
			double brakeCoef = 0;
		//atmospheric drag 
			double cd;
		//initial velocity of the shuttle
			double v0;
		//velocity
			double v;
		//runway length
			double d = 0.0;
		//acceleration
			double a;
		//end of runway
			double x = 0.0;
		//tolerance for the stopping distance
			static double t = 0.000001;
		//delta t
			static double deltat = 0.00001;
	
	//Define the input from user
		//initial velocity
			cout<<"v0 (m/s): ";
    			cin>>v0;
    		//atmoshperic drag coefficient
    			cout<<"c_d (1/m): ";
    			cin>>cd;
    		//stopping distance
    			cout<<"runway length (m): ";
    			cin>>d;

	//Define the boundaries
		//upper boundary for the stopping distance
			double bmax = pow(v0, 2)/(2.0*d);
		//lower boundary for the stopping distance
			double bmin = 0.0;

	//start by creating a loop that will keep happening until the difference 
	//between the end of the runway and the stopping distance is either lower 
	//or the same as the tolerance.
	while (abs(d-x)>=t){
	//midpoint of b
		brakeCoef = (bmax+bmin)/2.0;
	//resetting the acceleration 
		a = -(brakeCoef+cd*pow(v0,2));
		v=v0;
		x=0;
		//only make calculations if the velocity is positive
		while(v>0.0){
			v=v+a*deltat;	
			x=x+v*deltat;
			a = -(brakeCoef+cd*pow(v,2));
				
		}
    	//creating the if statements to find the upper and lower boundaries
    	//making the if statement so if the stopping distance is too small, this makes the
    	//upper boundary equal to the midpoint, cutting the distance in half.
    		if((d-x)>=t){
    			bmax = brakeCoef;
    		}

	//making the if statement so if the stopping distance is too large, this makes the
    	//lower boundary equal to the midpoint, cutting the distance in half.
    		if((d-x)<-t){
    			bmin = brakeCoef;
    		}	
    	}
	//final output
	cout << "b_optimal = " << brakeCoef <<endl;

	return 0;
}
