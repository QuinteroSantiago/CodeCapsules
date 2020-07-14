/*Program Description:
This program asks the user to input the number of books they purchased
this month. Then, it validates whether the amount of books is a positive 
integer. Finally, it checks how many books the person read to award a 
certain amount of points. If the person purchased 0 books then they 
will have 0 points. If the person purchased 1 book then they will have 5
points. If the person purchased 2 books then they will have 15 points. 
If the person purchased 3 books then they will have 30 points. If the 
person purchased 4 or more books then they will have 50 points.
*/

#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{   
    //Program code goes here
    //Initializing variable needed
    int books;

    //Initializing output && asking user for input
    cout << "Online Book Club Awards\n\n";
    cout << "Enter the number of books purchased this month: ";
    cin >> books;
    cout << endl;


    //If statement to check if the input is valid.
    //Needs positive int. 
    while(!cin || books < 0)
    {
        cout << "Invalid amount entered, try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> books;
        cout << endl; 
    }

    //Categorizing books and equate a certain amount of points per month   
    if(books == 0)
    {
        cout << "Congratulations! You have earned 0 points this month." << endl;
    }
    else if (books == 1)
    {
        cout << "Congratulations! You have earned 5 points this month." << endl;
    }
    else if (books == 2)
    {
        cout << "Congratulations! You have earned 15 points this month." << endl;
    }
    else if (books == 3)
    {
        cout << "Congratulations! You have earned 30 points this month." << endl;
    }
    //Since the input needs to be a positive integer, the remaining possible values
    //for books are (books >= 4). Therefore an else statement is ok to use.
    else
    {
        cout << "\nCongratulations! You have earned 50 points this month." << endl;
    }
        
    system("pause");
    return 0;
}
