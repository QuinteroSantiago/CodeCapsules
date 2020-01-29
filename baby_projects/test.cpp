#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    int s;
    cout << "This is just a test\n\n";
    cout << "Testing the amount of iterations a while loop has.\n";
    cout << endl;
    s = 1+(rand()%6);
    cout << s << endl;

    if(s % 2 == 0)
    {
        cout << "Even rolled, you win $1\n\n";
    }
    else
    {
        cout << "Odd rolled, you lose $1\n\n";
    }

    s = 3;
    cout << s << endl;

    if(s % 2 == 0)
    {
        cout << "Even rolled, you win $1\n\n";
    }
    else
    {
        cout << "Odd rolled, you lose $1\n\n";
    }
}
