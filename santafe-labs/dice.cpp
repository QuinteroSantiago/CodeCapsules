/*
Program Description:
    C++ program that simulates a game of chance using object-oriented principles.  
To begin, the program prompts and reads in the user's starting balance value.  
This value is validated. The minimum balance must be at least $1 (one dollar).  
The random generator produces a value between 1 and 6 (similar to a die).  
If the random generator number is an even number, the user wins $1.  If the random generator 
number is an odd number, the user loses $1. The user may play as much as they want as long 
as they have at least $1 balance. If the balance falls below $1, the game is over.  
If the user wishes to continue to play, the random generator is called again.  
Odd loses $1 and even wins $1. The program must keep up with the balance of the user.  
With each instance, the balance is displayed along with if the user won $1 or lost $1.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//Class for all functions and variables of game
class Game
{
    private:
        //Initializing Variables
        int balance;
        int randValue;
        char decision;
        
        //Validates if balance is in the correct format
        //Correct format = a positive int value for balnce
        void validateBalance()
        {
            while (!balance || balance < 0)
            {
                cout << "Invalid amount entered, try again: $";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> balance;
                cout << "\n";
            }
        }

        //Validates if decision is in the correct format
        //Correct format = either a 'Y','y','N',or 'n'
        void validateAgain()
        {
            while ((decision != 'Y') && (decision != 'y') && (decision != 'N') && (decision !='n'))
            {
                cout << "Invalid option selected, try again. (y=yes,n=no): ";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> decision;
                cout << "\n";
            }
        }

    public:
        //Constructor 
        Game(int b, int r, char d)
        {
            balance = b;
            randValue = r;
            decision = d;
        }

        //Reads in the starting balance entered from the user and validates it
        void setBalance(int input)
        {
            balance = input;
            validateBalance();
        }

        //Returns current balance
        int getBalance()
        {
            return balance;
        }

        //Calls the random generator to return a value between 1 and 6
        void roll()
        {
            cout << "Rolling....\n\n";
            randValue = 1+(rand()%6);
        }

        //Display the results of the roll (odd or even) and the user's balance
        void display()
        {
            //Checks if the remainder of the randValue has a remainder of 2 which would
            //mean that it is divisible by 2 
            if(randValue % 2 == 0)
            {
                cout << "Even rolled, you win $1\n\n";
                ++balance;
                cout << "Balance = $" << balance << "\n\n";
            }

            else
            {
                cout << "Odd rolled, you lose $1\n\n";
                --balance;
                cout << "Balance = $" << balance << "\n\n";
            }
        }

        //Determines if the user wants to roll again or quit the game
        void again()
        {
            if(balance > 0)
            {
                cout << "Roll again (y = yes,n = no): ";
                cin >> decision;
                cout << "\n";
                validateAgain();
            }
        };

        //returns current decision
        char getDecision()
        {
            return decision;
        }
};

//Main
int main()
{
    //Initializing and Constructing variables and classes
    Game game(1,0,'y');
    int balance;

    //Initializing program
    cout << "Rock Your World!\n\n";

    //Asking User for Input and validating it
    cout << "Enter your starting balance (minimum of $1): $";
    cin >> balance;
    cout << "\n";
    game.setBalance(balance);
    cout << "Starting Balance = $" << game.getBalance() << "\n\n";

    //While the user decides not to end the game and the balance is above zero, the game will keep going.
    while(((game.getDecision() != 'N') && (game.getDecision() != 'n')) && (game.getBalance() > 0))
    {
        game.roll();
        game.display();
        game.again();
    }
    
    //Ending of game
    cout << "Game Over. Ending Balance = $" << game.getBalance() << "\n\n";
    cout << "Thanks for playing!\n";

    system("pause");
    return 0;
}
