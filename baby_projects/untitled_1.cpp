#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class Book
{
    private:
        string title;
        string genre;
        int minutes_spent_reading;
        int rating;


        void validate_rating()
        {
            while (rating < 0 || rating > 5)
            {
                cout << "You cannot rate a book better than 5 nor lower than 0, try again...\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> minutes_spent_reading;
                cout << "\n";
            }
        }


    public:
        Book()
        {
            title = " ";
            genre = " ";
            minutes_spent_reading = 0;
            rating = 0;
        }

        void set_rating()
        {
            cout << "What would you rate this book?\n";
            cin >> rating;
            validate_rating();

        }

};

int main()
{
    Book book();

    book.set_rating();

    system("pause");
    return 0;
}