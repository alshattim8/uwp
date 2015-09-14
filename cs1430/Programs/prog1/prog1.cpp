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
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;


string data; // Variable for the input command
float radius; // Variable for the input radius
const double PI = 3.14159265;

// Commands to be checked with the input
string diameter = "diameter";
string perimeter = "perimeter";
string area = "area";

// Variables for the answer equations
float answerDiameter;
float answerPerimeter;
float answerArea;

int dataError() 
	// Function to display an error with the input command.
{
	cout << "You entered <" <<  data << "> for a command." << endl;
	cout << "You should have entered either diameter, perimeter, or area."
		<< endl;
	return 0;
}

int radiusCheck() 
	// Function to check for and display an error with the input radius
{
	if (radius <= 0)
	{
		cout << "You entered " << radius << " for the value for the radius."
			<< endl;
		cout << "You should have entered a positive value." << endl;
	}
	return 0;
}

int debug() // Function to check for input errors
{
	if (data != diameter)
	{
		radiusCheck();
		dataError();
	}
	else if (data != perimeter)
	{
		radiusCheck();
		dataError();
	}
	else if (data != area)
	{
		radiusCheck();
		dataError();
	}
	else
	{
		radiusCheck();
	}
	return 0;
}

int answer() 
	// Function to calculate the answer
{
	if (data == area) 
		// If statement for calculating area
	{
		answerArea = (PI * pow(radius, 2)) / 2;
		cout << "The area of a semicircle with radius " << radius 
			<< " is " << answerArea << "." << endl;
	}
	else if (data == perimeter) 
		// If statement for calculating perimeter
	{
		answerPerimeter = radius * (2 + PI);
		cout << "The perimeter of a semicircle with radius " << radius 
			<< " is " << answerPerimeter << "." << endl;
	}
	else if (data == diameter) 
		// If statement for calculating diameter
	{
		answerDiameter = 2 * radius;
		cout << "The diameter of a circle with radius " << radius 
			<< " is " << answerDiameter << "." << endl;
	}
	return 0;
}

int main() 
	// Main function
{
	// Initial output
	cout << "Input a command of either diameter, perimeter or area," 
		<< endl;
	cout << "followed by a space, and float value for the radius." 
		<< endl;
	cin >> data >> radius;
	cout << endl;

	// Inital error check in an if/else statement
	if ((radius > 0) && ((data == diameter) || (data == perimeter) 
	|| (data == area)))
	{
		answer();
	}
	else
	{
		debug();
	}

	return 0;
}

