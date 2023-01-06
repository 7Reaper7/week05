#include<iostream>
#include<cmath>
using namespace std;

float quadraticPositive(float, float, float);
float quadraticNegative(float, float, float);

main()
{

	system("cls");
	float a,b,c;
	float result, result1;
	cout << "Enter a => ";
	cin >> a;
	cout << "Enter b => ";
	cin >> b;
	cout << "Enter c => ";
	cin >> c;	
	result = quadraticPositive(a, b, c);
	result1 = quadraticNegative(a, b, c);
	cout << "x =  " << result << " and " << "x =  " << result1;
	
}

float quadraticPositive(float a, float b, float c)
{

	float b_square, det, numerator, result, square;
	b_square = pow(b,2);
	det = b_square - (4*a*c);
	square = sqrt(det);
	numerator = (-b) + square;
	result = numerator/(2*a);
	return result;

}

float quadraticNegative(float a, float b, float c)
{
	
	float b_square, det, numerator, result, square;
	b_square = pow(b,2);
	det = b_square - (4*a*c);
	square = sqrt(det);
	numerator = (-b) - square;
	result = numerator/(2*a);
	return result;

}
