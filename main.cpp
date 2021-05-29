#include "DateType.h"
#include <iostream>
#include <limits>

using namespace std;

enum RelationType {LESS, EQUAL, GREATER};       //New Addition to the Program

int main()
{
    string outFileName; int m, d, y, daysAway; ofstream outFile;
    cout << "Enter name of output file name: ";
    cin >> outFileName; outFileName += ".txt"; outFile.open(outFileName.c_str());

    cout << "Enter a date in one line (day month year): " ;
    cin >> m >> d >> y; Date date1(m,d,y);

    bool done=false;

    //prompt user
    outFile << "Entered Date is " << date1.getDay() << " " << date1.getMonth() << " " << date1.getYear() << endl;
    while(!done)
    {
        cout << endl << "1) Find date 'n' days away from entered date " << endl;
        cout << "2) View name of month " << endl;
        cout << "3) Compare entered date with another date " << endl;
        cout << "Choose an option: ";
        int op;
        while(!(cin >> op))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please re-enter: ";
        }
        cout << endl; int n;
        if(op==1)
        {
            cout << "Enter n: ";
            while(!(cin >> n))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please re-enter: ";
            }
            Date date2=date1.Adjust(n);
            outFile << n << " days away is " << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;
        }
        else if(op==2)
            outFile << "The Month is " << date1.getMonthAsString() << endl;
        else if(op==3) {
            cout << "Enter a date to compare with in the previous format: " << endl;
            cin >> m >> d >> y; Date date2(m,d,y);

            string outFileString;
            switch(date1.ComparedTo(date2)) {

                case LESS:
                    outFile << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear();
                    outFile << " comes before ";
                    outFileString=" comes before";
                    outFile << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;
                    break;

                case EQUAL:
                    outFile << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear();
                    outFile << " is the same as ";
                    outFileString=" is the same as ";
                    outFile << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;
                    break;

                case GREATER:
                    outFile << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear();
                    outFile << " comes after ";
                    outFileString=" comes after ";
                    outFile << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;
                    break;

                default:
                    cout << "Something went seriously wrong dude, fix your code. ";
            }
            outFile << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear();
            outFile << outFileString << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;
        }
        cout << "Done writing in file " << endl;
        cout << "\nContinue with another option? (y/n) " << endl;
        char x; cin >> x;
        if(x=='n')
            done=true;
    }
    cout << endl << "Thank you! (: " << endl;
    return 0;
}
