//---------------------------------------------------------------------
//
// Name:    John W Hunter
//
// Course:  CS 1430, Section 06, Fall 213
//
// Purpose: Calculates and prints the diameter, the perimeter, or the  
//				area of a semicircle, depending upon the given radius of 
//				the corresponding circle and the given command. 
//
// Input:   A string (either "diameter", "perimeter", or "area") 
//				followed by a positive floating-point number representing  
//				the radius of semicircle.
//				ex: "area 3.5"
//
// Output:  The correct diameter, perimeter, or area of the semicircle.
//				ex: "The diameter of a circle with radius 7.65 is 15.3."
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float radius; // Variable for the input radius
string command; // Variable for the input command

const double PI = 3.14159265; // Set constant for pi
const int TWO = 2; // Set constant for 2

// Commands to be checked with the input
const string DIAMETER = "diameter";
const string PERIMETER = "perimeter";
const string AREA = "area";

void radiusError() 
// Function to display an error with the input radius
{
	cout << "You entered " << radius << 
		" for the value for the radius." << endl 
		<< "You should have entered a positive value." << endl;
}

bool radiusCheck()
// Function to check for a radius error and return a bool
{
	return radius > 0;
}

void main()
{
// Initial output
	cout << "Input a command of either diameter, perimeter or area,"
		<< endl << "followed by a space, and float value for the radius."
		<< endl;
	cin >> command >> radius;
	cout << endl;

// To check the input command and display results
	if ( command == AREA )
		if ( radiusCheck() == true ) // To check the radius
			cout << "The area of a semicircle with radius " << radius 
				<< " is " << ( PI * pow(radius, TWO) ) / TWO << "." << endl;
		else
			radiusError();
	else if ( command == PERIMETER )
		if ( radiusCheck() == true ) // To check the radius
			cout << "The perimeter of a semicircle with radius " << radius
				<< " is " << radius * ( TWO + PI ) << "." << endl;
		else
			radiusError();
	else if ( command == DIAMETER )
		if ( radiusCheck() == true ) // To check the radius
			cout << "The diameter of a circle with radius " << radius 
				<< " is " << TWO * radius << "." << endl;
		else
			radiusError();
	else // Result of an incorrect command
	{
		if ( radiusCheck() == false ) // Check for a radius error
			radiusError();
		cout << "You entered <" <<  command << "> for a command." << endl 
			<< "You should have entered either diameter, perimeter, " 
			<< "or area." << endl;
	}
}