/*Program Description:
This program reads an input file of data of today's sales from three stores. 
Then it rounds to the nearest $1000 for each of the stores. 
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    //Initializing variables
    int i = 1;
    ifstream inFile;
    int line;

    //Initializing Program
    cout << "Today's Sales Chart\n\n";
    cout << "Gathering input from file...\n\n";
        inFile.open("Sales.txt");
    cout << "Daily Sales (each *=$1000)\n\n";

    //if loop to check if file opens
    if(inFile)
    {
        //while loop to read each line from input
        while(inFile >> line)
        {
            //i is used as variable to follow store number
            cout << "Store " << i << ": ";
                //while loop to output an asterisk for every 1000 
                //counted in the line being currently read. 
                while(line > 1000)
                {
                    cout << "*";
                    line = line - 1000;
                }
                    //if file in case there is need to round up numbers
                    if(line >= 500)
                    {
                        cout << "*";
                    }
            cout << endl;
            //store count going up by one
            ++i;
        }
    }
    else
    {
        cout << "Error on file open\n";
        return 1;
    }
    //Close input file when it is not needed anymore.
    inFile.close();

    system("pause");
    return 0;
}
