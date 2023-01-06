#include<iostream>
#include<cmath>
using namespace std;

string check(char);

main()
{

	system("cls");
	char input;
	string output;
	cout << "Enter Alphabet=> ";
	cin >> input;
	output = check(input);
	if(output == "uppercase")
	{
		cout << input << " is uppercase";
	}
	if(output == "lowercase")
	{
		cout << input << " is lowercase";
	} 

}

string check(char input)
{
	
	if(input == 'A')
	{
		return "uppercase";
	}
	if(input == 'a')
	{
		return "lowercase";
	}

}