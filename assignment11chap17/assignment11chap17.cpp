/*Kyle Flores adv c++
Assignment 11 is regarding exceptions and handling of them. 
Division by zero, 
rethrowing exceptions, 
stack unwinding, 
new -> bad-alloc and 
new -> set_new_handler 
using try throw catch
 
*/

#include <iostream>
#include <stdexcept>
#include <new>
void introduction();
void menu();
int divByZero(int, int);

void throws();

void stack1();
void stack2();
void stack3();
void newHand();


using namespace std;




int main()
{
    introduction();
    int menuInt, num1, num2, res; 
    char val;
    double* ptr[40];

    bool repeat = false;

    while (!repeat) {
        menu();
        cin >> menuInt;

        switch (menuInt)
        {
        default:
            cout << "\nInvalid option. Please select an approriate menu option.";
            break;
        case 0:
            cout << "\nTerminating program.";
            repeat = true;
            break;
        case 1:
            cout << "\nInput 2 numbers, receive quotient:\n ";
            cin >> num1 >> num2;
            try {res = divByZero(num1, num2);}catch (runtime_error& r) { cout << "\nError occured " << endl << r.what(); }
            break;
        case 2:
            try {
                cout << "\nthrow on throw in main";
                throws();
            }
            catch (const exception&) { cout << "\nthrown on thrown catch in main\n"; }
            cout << "\nMain controls again\n" << endl;
            break;
        case 3:
            try {
                cout << "\nStack 1 for unwinding example...\n";
                stack1();
            }
            catch (runtime_error& r) {
                cout << "\nError encountered: " << r.what() << endl;
                cout << "\nBack in main... " << endl;
            }
            break;
        case 4:

            try {
                for (size_t x{ 0 }; x < 40; ++x) {
                    ptr[x] = new double[40005000]{};
                    cout << "whaaaa" << x << "new alloc\n";
                }
            }
            catch (bad_alloc& tooMany) { cout << "Bad Alloc issue: " << tooMany.what() << endl; }
            break;
        case 5:
            set_new_handler(newHand);
                for (size_t x{ 0 }; x < 40; ++x) {
                    ptr[x] = new double[40005000]{};
                    cout << "whaaaa" << x << "new alloc\n";
                }
         

        };//end switch

    }//end while



}


void introduction() {
    cout << "\nAssignment 11 is regarding exceptions and handling of them";
}

void menu() {
    cout << "\nOption (0): QUIT"
        << "\nOption (1): Division by zero"
        << "\nOption (2): rethrowing exceptions"
        << "\nOption (3): stack unwinding"
        << "\nOption (4):  new->bad - alloc"
        << "\nOption (5): new->set_new_handler and Exit"
        << "\n\nPlease select:  ";
}

int divByZero(int a, int b) {
    if (b == 0) {
        throw runtime_error("\nAttempt to div by zero");
        return (a / b);
    }
}
void throws() {
    try {
        cout << "\nJust throwing exceptions in throw\n";
        throw exception{};
    }
    catch (const exception&) { cout << "\nthrow on throw\n"; throw; }

}

void stack1() { cout << "\nCall S2"; stack2(); }
void stack2() { cout << "\nCall S3"; stack3(); }
void stack3() {
    cout << "\nGonna mess some stuff up in here...\n";
    throw runtime_error{ "Goodbye cruel world"
    };
}
void newHand() {
    cerr << "\nNew Handler called\n";
    exit(EXIT_FAILURE);
}