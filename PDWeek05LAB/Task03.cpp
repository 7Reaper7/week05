#include<iostream>
using namespace std;

void calculate(int, int);

// used global variables due to the skill purpose of the manual

    int working_hours, hours_in_working_days;
    float working_days;

main()
{
    system("Cls");

    int hour, days, workers;
    int remaining;

    cout << "Enter the amount of hours needed=> ";
    cin >> hour;
    cout << "Enter the days till deadline=> ";
    cin >> days;
    cout << "Enter the number of workers at hand=> ";
    cin >> workers;

    calculate(days, workers);

    if(working_hours>=hours_in_working_days)
    {

        remaining = working_hours - hour;
        cout << "Yes! " << remaining << " hours left.";
    
    }
    if(working_hours<hours_in_working_days)
    {
    
        remaining = hour - working_hours;
        cout << "Not enough time! " << remaining << " hours needed.";
    
    }

}

void calculate(int days, int workers)
{
    working_days = days - (days * 0.1);
    hours_in_working_days = working_days * 24;
    working_hours = workers * 10 * working_days;
}