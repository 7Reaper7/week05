#include<iostream>
#include<cmath>
using namespace std;

bool issym(int);

main()
{

	system("cls");
	int num;
	bool result;
	cout << "Enter a three digit number=> ";
	cin >> num;
	result = issym(num);
	if(result == 0)
	{
		cout << num << " is not symmetrical." << endl;
	}
	if(result != 0)
	{
		cout << num << " is symmetrical." << endl;
	}
}

bool issym(int num)
{
	
	int n1,n3;

	n1 = num%10;
	n3 = (num/100);

	if(n1==n3)
	{
		return true;
	}
	
	return false;

}