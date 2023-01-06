#include<iostream>
#include<cmath>
using namespace std;

string ishism(int);

main()
{

	system("cls");
	int num;
	string result;
	
	cout << "Enter a five digit number=> ";
	cin >> num;
	
	result = ishism(num);
	
	if(result == "Evenish")
	{
		cout << num << " is Evenish.";
	}
	if(result == "Oddish")
	{
		cout << num << " is Oddish.";
	}
}

string ishism(int num)
{
	
	int n1,n2,n3,n4,n5;
	int sum;

	n1 = num%10;
	n2 = (num/10) % 10;
	n3 = (num/100) % 10;
	n4 = (num/1000) % 10;
	n5 = num/10000;
	
	sum = n1+n2+n3+n4+n5;
	
	if(sum%2==0)
	{
		return "Evenish";
	}
	if(sum%2==1)
	{
		return "Oddish";
	}

}