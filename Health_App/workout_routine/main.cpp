#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class workout_routine
{
    private:
        int volume; //BULK == 2, CUT == 1, MAINTAIN == 1
        string volume_1;
        int user_weight;
    public:
        void input_weight();
        void bulk_cut_maintain();
        int get_volume();
        void bulk_push();
        void bulk_pull();
        void bulk_legs();
        void cut_push();
        void cut_pull();
        void cut_legs();        
        void maintain_push();
        void maintain_pull();
        void maintain_legs();
        void cardio();
        void write_log();
};
void workout_routine::input_weight()
{
    cout << "Sorry for asking but may I know how much do you weigh in pounds?\n";
    cin >> user_weight;
}
int workout_routine::get_volume()
{
    return volume;
}
void workout_routine::bulk_cut_maintain()
{
    
    bool loop = false;
    do
    {
        cout << "\n***Do you want to Bulk, Cut, or Maintain?***\n\n";
        cin >> volume_1;

        //Convert volume_1 toupper in order to have no case sensitivity

        if(volume_1 == "BULK")
        {
            volume = 2;
            loop = true;
        }
        else if(volume_1 == "CUT")
        {
            volume = 1;
            loop = true;
        }
        else if(volume_1 == "MAINTAIN")
        {
            volume = 0;
            loop = true;
        }
        else
            cout << "\nI didn't understand that, please try again.\n\n";

    } while (loop = false);
    

}
void workout_routine::bulk_push()
{
    cout << "Bulk Push\n";
}
void workout_routine::bulk_pull()
{
    cout << "Bulk Push\n";
}
void workout_routine::bulk_legs()
{
    cout << "Bulk Push\n";
}
void workout_routine::cut_push()
{
    cout << "Bulk Push\n";

}
void workout_routine::cut_pull()
{
    cout << "Bulk Push\n";

}
void workout_routine::cut_legs()
{
    cout << "Bulk Push\n";

}
void workout_routine::maintain_push()
{
    cout << "Bulk Push\n";

}
void workout_routine::maintain_pull()
{
    cout << "Bulk Push\n";

}
void workout_routine::maintain_legs()
{
    cout << "Bulk Push\n";
}

void workout_routine::cardio()
{

}

int main()
{
    int choice;
    workout_routine daily;
    cout << "***Welcome to your daily Workout Routine***\n";
    daily.input_weight();
    while(true)
    {
        cout << "What workout routine did you have in mind today?";
        cout << "\n\t1-->PUSH Routine";
        cout << "\n\t2-->PULL Routine";
        cout << "\n\t3-->LEG Routine";
        cout << "\n\t4-->Just Cardio";
        cout << "\nEnter your choice: ";        
        cin >> choice;
        switch(choice)
        {
            case 1:
                daily.bulk_cut_maintain();
                if (daily.get_volume() == 2)
                {
                    daily.bulk_push();
                }
                else if (daily.get_volume() == 1)
                {
                    daily.cut_push();
                }
                else if (daily.get_volume() == 0)
                {
                    daily.maintain_push();
                }
                else
                {
                    cout << "I don't know what you did, but you broke the program, well done...\n"; 
                }
                
                break;
            case 2:
                daily.bulk_cut_maintain();
                if (daily.get_volume() == 2)
                {
                    daily.bulk_pull();
                }
                else if (daily.get_volume() == 1)
                {
                    daily.cut_pull();
                }
                else if (daily.get_volume() == 0)
                {
                    daily.maintain_pull();
                }
                else
                {
                    cout << "I don't know what you did, but you broke the program, well done...\n"; 
                }
                break;
            case 3:
                daily.bulk_cut_maintain();
                if (daily.get_volume() == 2)
                {
                    daily.bulk_legs();
                }
                else if (daily.get_volume() == 1)
                {
                    daily.cut_legs();
                }
                else if (daily.get_volume() == 0)
                {
                    daily.maintain_legs();
                }
                else
                {
                    cout << "I don't know what you did, but you broke the program, well done...\n"; 
                }                break;
            case 4:
                daily.cardio();
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


void workout_routine::write_log()
{
    ofstream outfile;
    outfile.open("workout.routine", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
