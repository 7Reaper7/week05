#include<iostream>
using namespace std;

void calFinal(float);
void calTax(char, float);

// used global variables due to the skill purpose of the manual

    float tax_ammount;
    float final_Price;
    string name;

main()
{
    system("Cls");

    float price;
    char type_code;

    cout << "Enter the price of the vehicle=> ";
    cin >> price;
    cout << "Enter the type of vehicle=> ";
    cin >> type_code;

    calTax(type_code, price);
    calFinal(price);
    
    cout << "The final price on a vehicle of type " << name << " after adding the tax is " << final_Price;

}

void calTax(char type_code, float price)
{
    
    float rate = 6.0;

    if(type_code == 'M')
    {
        name = "Motorcycle";
    }
    if(type_code == 'E')
    {
        name = "Electric";
        rate = 8.0;
    }
    if(type_code == 'S')
    {
        name = "Sedan";
        rate = 10.0;
    }
    if(type_code == 'V')
    {
        name = "Van";
        rate = 12.0;
    }
    if(type_code == 'T')
    {
        name = "Truck";
        rate = 15.0;
    }

    tax_ammount = price * (rate/100);
}

void calFinal(float price)
{
    final_Price = price + tax_ammount;
}