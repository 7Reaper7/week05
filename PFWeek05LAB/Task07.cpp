#include<iostream>
#include<cmath>
using namespace std;

string tens(int);
string ones(int);

main()
{

	system("cls");
	int input, n2=1;
	int oneDigit;
	cout << "Enter a number between 1-99(except 11-19)=> ";
	cin >> input;
	
	if(input>19)
	{
		n2 = input / 10;
		input = input % 10;	
		cout << tens(n2);
	}
	
	
	cout << ones(input);
	

}

string tens(int n2)
{

	if(n2==2)
	{
		return "twenty ";
	}
	if(n2==3)
	{
		return "thirty ";
	}
	if(n2==4)
	{
		return "fourty ";
	}
	if(n2==5)
	{
		return "fifty ";
	}
	if(n2==6)
	{
		return "sixty ";
	}
	if(n2==7)
	{
		return "seventy ";
	}
	if(n2==8)
	{
		return "eighty ";
	}
	if(n2==9)
	{
		return "ninety ";
	}

}

string ones(int input)
{

	if(input==1)
	{
		return "one";
	}
	if(input==2)
	{
		return "two";
	}
	if(input==3)
	{
		return "three";
	}
	if(input==4)
	{
		return "four";
	}
	if(input==5)
	{
		return "five";
	}
	if(input==6)
	{
		return "six";
	}
	if(input==7)
	{
		return "seven";
	}
	if(input==8)
	{
		return "eight";
	}
	if(input==9)
	{
		return "nine";
	}
	if(input==10)
	{
		return "ten";
	}

}