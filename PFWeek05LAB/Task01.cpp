#include<iostream>
#include<cmath>
using namespace std;

float calheight(float, float);

main()
{

	system("cls");
	float distance;
	float angle;
	float result;
	cout << "Enter distance=> ";
	cin >> distance;
	cout << "Enter angle of elevation=> ";
	cin >> angle;
	result = calheight(distance, angle);
	cout << "Height of the tree is=> " << result;

}
	
float calheight(float distance, float angle)
{

	float radian, height;
	radian = angle/57.2958;
	height = tan(radian) * distance;
	return height;

}