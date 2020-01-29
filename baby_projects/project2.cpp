/*Program Description:
This program asks the user for the number of male and female 
students in a class and outputs the percentage of males and
female students in said class rounded to 2 decimal places.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
       //program code goes here
       //Description of process with double space
       cout << "Percent of students by gender:\n" << endl;

       //defining variables
       float female_count, male_count;

       //Asking user for input
       cout << "Enter the number of females in the class: ";
       cin >> female_count;
       cout << "Enter the number of males in the class: ";
       cin >> male_count;

       //Output
       cout << fixed << setprecision(2);
       cout << "Percentage of females: " << ((female_count)/((female_count) + male_count)) * 100 << "%" << endl;
       cout << "Percentage of males:   " << ((male_count)/((female_count) + male_count)) * 100 << "%" << endl;

       //For teacher display purposes
       system("pause");
       return 0;
}