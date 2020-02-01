#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class diet_data
{
    private:
        int meals;
    public:
        void meal_counter();
        void cal_find();
        void protein_find();
        void fat_find();
        void carb_find();
        void all_find();
};
void diet_data::meal_counter()
{
    cout << "Meals in a day: ";
    cin >> meals;
    for (int i = 1; i <= meals; ++i)
    {
        cout << "MEAL #" << i << endl;
        cout << endl;
    }
}
void diet_data::cal_find()
{
    cout << "\n***DIET BASED ON KILOCALORIES***\n\n";
    meal_counter();
    exit(0);
}
void diet_data::protein_find()
{
    cout << "\n***DIET BASED ON PROTEIN***\n\n";
    meal_counter();
    exit(0);
}
void diet_data::fat_find()
{
    cout << "\n***DIET BASED ON FAT***\n\n";
    meal_counter();
    exit(0);
}
void diet_data::carb_find()
{
    cout << "\n***DIET BASED ON CARBOHYDRATES***\n\n"; 
    meal_counter();
    exit(0);    
}
void diet_data::all_find()
{
    cout << "\n***DIET BASED ON KILOCALORIES,PROTEIN, FAT, AND CARBOHYDRATES***\n\n"; 
    meal_counter();
    exit(0);
}

int main()
{
    int choice;
    diet_data D;
    cout << "***Welcome to Diet Provider***";
    while(true)
    {
        cout << "Select from one of the options below: ";
        cout << "\n\t1-->Find a diet based on Calories";
        cout << "\n\t2-->Find a diet based on Protein";
        cout << "\n\t3-->Find a diet based on Fat";
        cout << "\n\t4-->Find a diet based on Carbs";
        cout << "\n\t5-->Find a diet based on all of the above(NOT CURRENTLY AVAILABLE)";
        cout << "\n\t6-->I already have a diet, thanks!";
        cout << "\nEnter your choice: ";        
        cin >> choice;
        switch(choice)
        {
            case 1:
                D.cal_find();
                break;
            case 2:
                D.protein_find();
                break;
            case 3:
                D.fat_find();
                break;
            case 4:
                D.carb_find();
                break;
            case 5:
                D.all_find();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "\nPlease enter a valid choice\n";
        }
    }
    system("pause");
    return 0;
//caloriesMan = ( (ageYears * 0.2017) - (weightPounds * 0.09036) + (heartBPM * 0.6309) - 55.0969 ) * timeSeconds / 4.184
//caloriesWoman = ( (ageYears * 0.074) - (weightPounds * 0.05741) + (heartBPM * 0.4472) - 20.4022 )* timeSeconds / 4.184
}