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

const double PI = 3.14159265; // Set constant for pi
const int TWO = 2; // Set constant for 2

void main()
{
	float radius; // Variable for the input radius
	string command; // Variable for the input command

// Initial output
	cout << "Input a command of either diameter, perimeter or area,"
		<< endl << "followed by a space, and float value for the radius."
		<< endl;
	cin >> command >> radius;
	cout << endl;

// Radius check
	if (radius > 0) 
	{
// Check for area command and display the results
		if ( command == "area" )
			cout << "The area of a semicircle with radius " << radius 
				<< " is " << ( PI * pow(radius, TWO) ) / TWO << "." << endl;
// Check for perimeter command and display the results
		else if ( command == "perimeter" )
			cout << "The perimeter of a semicircle with radius " << radius
				<< " is " << radius * ( TWO + PI ) << "." << endl;
// Check for diameter command and display the results
		else if ( command == "diameter" )
			cout << "The diameter of a circle with radius " << radius 
				<< " is " << TWO * radius << "." << endl;
 // Result of an incorrect command
		else if ( ( command != "area" ) || ( command != "perimeter" ) 
			|| ( command != "diameter" ) )
		{
		cout << "You entered <" <<  command << "> for a command." << endl 
			<< "You should have entered either diameter, perimeter, " 
			<< "or area." << endl;
		}
		else;
	}
	else
	{
		cout << "You entered " << radius << 
			" for the value for the radius." << endl 
			<< "You should have entered a positive value." << endl;
// Command check if radius is incorrect
		if ( ( command == "area" ) || ( command == "perimeter" )
			|| ( command == "diameter" ) );
		else
		{
			cout << "You entered <" <<  command << "> for a command." 
				<< endl 
				<< "You should have entered either diameter, perimeter, "
				<< "or area." << endl;
		}
	}
}