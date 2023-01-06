#include<iostream>
#include<cmath>
using namespace std;

main()
{

	system("cls");
	int hour, mins;
	int modmins, modhour;

	cout << "Enter Hour(s)=> ";
	cin >> hour;
	cout << "Enter Minute(s)=> ";
	cin >> mins;
	
	if(mins<45)
	{
		modmins = mins+15;
		cout << hour << ":" << modmins;
		return 0;
	}
	if(hour<23)
	{
		modhour = hour + 1; 
		modmins = (mins+15) % 60;
		cout << modhour << ":" << modmins;
		return 0;
	}
	if(hour==23)
	{
		hour = 0;
		modmins = (mins+15) % 60;
		cout << hour << ":" << modmins;
	}

}