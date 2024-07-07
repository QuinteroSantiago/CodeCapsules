/*
Program Description:
This program determines which of a company's four divisions 
(North, South, East, West) has the greatest sales for the quarter.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//functions
float getSales(string division);
void validate(float& sales);
void findHighest(float n, float s, float e, float w);

int main()
{
    //Declare variables to store sales data
    float north_sales;
    float south_sales;
    float east_sales;
    float west_sales;

    //Initializing Program
    cout << "This program determines which of the company's four divisions " 
         << "(North, South, East, West) has the greatest sales for the quarter.\n";

    //Gathering input from user
    north_sales = getSales("North");
    validate(north_sales);

    south_sales = getSales("South");
    validate(south_sales);

    east_sales = getSales("East");
    validate(east_sales);

    west_sales = getSales("West");
    validate(west_sales);

    //Output and calculations
    findHighest(north_sales, south_sales, east_sales, west_sales);
    system("pause");
    return 0;
}

//This function asks the user to input the sales for a specific division and gives that
//number as an output
float getSales(string division)
{
    float sales;
    cout << "\nPlease input the " << division << "'s division's quarterly sales figure: ";
    cin >> sales;
    return sales;
}

//Checks if sales data is a positive float.
void validate(float& sales)
{
    while(!sales || sales < 0)
    {
        cout << "\nError in sales format input, please try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> sales;
    }
}

//Finds division with highest sales
void findHighest(float n, float s, float e, float w)
{
    string division_1;
    if(n > s && n > e && n > w)
    {
        division_1 = "North";
    }
    else if(s > n && s > e && s > w)
    {
        division_1 = "South";
    }
    else if(e > n && e > s && e > w)
    {
        division_1 = "East";
    }
    else if(w > n && w > s && w > e)
    {
        division_1 = "West";
    }
    else
    {
        cout << "\nTwo or more divisions have the greatest sales for the quarter\n";
        exit(0);
    }

    cout << "\nThe " << division_1 << " division has the greatest sales for the quarter.\n";
}
