/*
Program Description:
C++ program that indicates the number of days in a month the 
temperature was above average, below average, and at the average for 
the month of November.  Using an array to count the 
number of days above average, below average, and average, read in an 
input file named NovTemps.txt that gives the temperature for each day 
for the month.  The input file should be located in the current 
directory.  If the temperature is above the average temperature, 
increment the count in the index of the array that holds the count 
for the days above average.  If the temperature is below the average 
temperature, increment the count in the index of the array that holds 
the count for the days below average.  If the temperature is equal to 
the average temperature, increment the count in the index of the array 
that holds the count for the days equal to the average temperature.

When the end of file has been reached, display the count for the number 
of days above average, the number of days below average, and the number 
of days equal to the average.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//Read in input file NovTemps.txt

//Calculate the average temperature of NovTemps.txt

//Array with three values: above average, below average, average.
//while loop counting all values of input file
    //if temp is above average, add count to above average array value.
    //if temp is below average, add count to below average array value.
    //if temp is average, add count to average array value.

class calculations
{
    private:
        ifstream inFile;
        int aboveTempCount;
        int belowTempCount;
        int averageTempCount;
        int averageTemp;

    public:

    calculations(int a, int b, int c, int d)
    {
        aboveTempCount = a;
        belowTempCount = b;
        averageTempCount = c;
        averageTemp = d;
    }

    void getFiles()
    {
        inFile.open("NovTemps.txt");
        if(!inFile)
        {
            cout << "Error reading file. Check if file is in current directory.\n\n";
            exit;
        }
        
    }
 
    void calcMeanTemp()
    {
    }

    void calcTempCounts()
    {
        
    }

    int getAboveTempCount()
    {
        return aboveTempCount;
    }

    int getBelowTempCount()
    {
        return belowTempCount;
    }

    int getAverageTempCount()
    {
        return averageTempCount;
    }

};

int main()
{
    cout << "November Temperatures.\n\n";
    cout << "Reading in temperature files...\n\n";
    calculations temp(0,0,0,0);

    cout << "In November temperature was above average " << temp.getAboveTempCount() << " times.\n\n" ;
    cout << "It was below average " << temp.getBelowTempCount() << " times.\n\n" ;
    cout << "And it was just average " << temp.getAverageTempCount() << " times.\n\n" ;

    system("pause");
    return 0;
}