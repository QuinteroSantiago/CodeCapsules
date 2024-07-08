#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

class user_data{
    private:
        char gender;
        int weight;
        int height;
        int age;
        int calories;
        int protein_grams;
    public:
        void data();
        void diet();
        int get_calories();
        int get_protein();
};

void user_data::data()
{
    cout << "***Diet Provider Main Function***";
    cout << "Are you a male of a female(M/F): ";
    cin >> gender;
    cout << "How much do you weight (kg): ";
    cin >> weight;
    cout << "How tall are you? (cm): ";
    cin >> height;
    cout << "How old are you? (years): ";
    cin >> age;
}
void user_data::diet()
{
    int basal_metabolic_rate;
    int activity_factor = 120; // Variable in future. This is for a sedentary lifestyle. 120 = 1.2
    if (gender == 'M' || gender == 'm') // Basal Metabolic Rate if user is a male
    {
        basal_metabolic_rate = (weight * 10) + (height * 6.25) - (age * 5) + 5; //Mifflin-St Jeor Equation
    }
    else if(gender == 'F' || gender == 'f') // Basal Metabolic Rate if user is a female
    {
        basal_metabolic_rate = (weight * 10) + (height * 6.25) - (age * 5) - 161; //Mifflin-St Jeor Equation
    }
    
    else // Average of Male and Females if person identifies as non-binary
    {
        basal_metabolic_rate = (weight * 10) + (height * 6.25) - (age * 5) - 78; // Non-scientifically sound equation
    }
    calories = (activity_factor * basal_metabolic_rate) / 100;
    protein_grams = (calories * .15) / 4;
}
int user_data::get_calories()
{
    return calories;
}
int user_data::get_protein()
{
    return protein_grams;
}


struct ideal_diet{
    int calories;
    int protein_grams;
};

int main()
{
    //Reads in CSV file line by line. 3
    //Creates lists of diets based on vector above. 4
    //Ask for years and weight of user.
    user_data user;
    user.data();
    //Creates ideal diet given the previous input. 2
    user.diet();
    struct ideal_diet user_diet;
    /*Test*/cout << user.get_calories() << " Calories.\n" << user.get_protein() << " protein grams.\n"; 

    user_diet.calories = user.get_calories();
    user_diet.protein_grams = user.get_protein();
    //Linear Search for diet that best correlates to .5
    system("pause");
    return 0;
}

/*
struct Recipe //This might go inside main or diet_data depending on input file location
{
    string *recipe_name;
    int calories;
    int protein;
    int fat;
    vector<int> macros{calories,protein,fat};
    int *time_of_meal;// 0 = Bfast, 1 = Lunch, 2 = Dinner
    string *ingredients;
};


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
    diet_data D; //Declaring diet_data class
    cout << "***Welcome to Diet Provider***";
    // IN PROGRESS READING IN recipes.csv file
    fstream recipes_file;
    recipes_file.open(recipes.csv, ios::in);
    
    Recipe *recipe = new Recipe;

    vector<string> row;
    string line, word, temp; 

    while (fin >> temp) { 
        row.clear();   
        getline(fin, line); 
        stringstream s(line); 
        while (getline(s, word, ', ')) { 
            row.push_back(word); 
        } 
    data.recipe_name;

    data.calories;
    data.fat;
    data.protein;

    data.sugar;
    data.time_of_meal;
    data.ingredients;
    //NEED FOR INPUTTING VARIABLES INTO STRUCT
    
    while(true)
    {
    // IN CONSTRUCTION   
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
}
*/