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

string command; // Variable for the input command
float radius; // Variable for the input radius
const double PI = 3.14159265; // Set constand for pi

// Commands to be checked with the input
string diameter = "diameter";
string perimeter = "perimeter";
string area = "area";

// Variables for the answer equations
float answerDiameter;
float answerPerimeter;
float answerArea;

int radiusError() 
	// Function to display an error with the input radius
{
	if (radius <= 0)
	{
		cout << "You entered " << radius << " for the value for the radius."
			<< endl;
		cout << "You should have entered a positive value." << endl;
	}
	return 0;
}

bool radiusCheck()
	// Function to check for a radius error and return a bool
{
	if (radius <= 0)
		return false;
	else
		return true;
}

int areaCalc()
	// Function to calculate the area
{
	if (radiusCheck() == true) // To check the radius
	{
		answerArea = (PI * pow(radius, 2)) / 2;
		cout << "The area of a semicircle with radius " << radius 
			<< " is " << answerArea << "." << endl;
	}
	else
		radiusError();
	return 0;
}

int perimeterCalc()
	// Function to calculate the perimeter
{
	if (radiusCheck() == true) // To check the radius
	{
		answerPerimeter = radius * (2 + PI);
		cout << "The perimeter of a semicircle with radius " << radius 
			<< " is " << answerPerimeter << "." << endl;
	}
	else
		radiusError();
	return 0;
}

int diameterCalc()
	// Function to calculate the diameter
{	
	if (radiusCheck() == true) // To check the radius
	{
		answerDiameter = 2 * radius;
		cout << "The diameter of a circle with radius " << radius 
			<< " is " << answerDiameter << "." << endl;
	}
	else
		radiusError();
	return 0;
}

int main()
{
	// Initial output
	cout << "Input a command of either diameter, perimeter or area," 
		<< endl;
	cout << "followed by a space, and float value for the radius." 
		<< endl;
	cin >> command >> radius;
	cout << endl;

	// To check the input command
	if (command == area)
		areaCalc();
	else if (command == perimeter)
		perimeterCalc();
	else if (command == diameter)
		diameterCalc();
	else // Result of an incorrect command
	{
		if (radiusCheck() == false) // Check for a radius error
			radiusError();
		cout << "You entered <" <<  command << "> for a command." << endl;
		cout << "You should have entered either diameter, perimeter, " 
			<< "or area." << endl;
	}

	return 0;
}