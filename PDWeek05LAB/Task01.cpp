#include<iostream>
#include<cmath>
using namespace std;

void calVolume(float, float, float, string);

// used global variables due to the skill purpose of the manual

	float vol;

main()
{

	system("cls");

	float length, height, width;
	string outputUnit;
	cout << "Enter the length of the pyramid=> ";
	cin >> length;
	cout << "Enter the width of the pyramid=> ";
	cin >> width;
	cout << "Enter the height of the pyramid=> ";
	cin >> height;
	cout << "Enter the Unit in which you want the output=> ";
	cin >> outputUnit;
	
	calVolume(length,height,width,outputUnit);
	 
	cout << vol << " cubic " << outputUnit;
}

void calVolume(float length, float height, float width, string outputUnit)
{

	vol = (length*width*height)/3;

	if(outputUnit=="milimeters")
	{
		vol=vol*pow(1000,3);
	}
	if(outputUnit=="centimeters")
	{
		vol=vol*pow(100,3);
	}
	if(outputUnit=="kilometers")
	{
		vol=vol/pow(1000,3);
	}

}