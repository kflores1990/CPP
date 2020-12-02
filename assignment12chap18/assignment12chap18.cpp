/*
Kyle Flores assignment 12 chap 18 reviews templates. The assignment provides an opportunity to 
create a stack template using the vector class vector<T> elements. 
Provided functionality include: push(), pop(), top(), clear(), empty();
both pop and top throw a handled exception if called when the stack is empty.
empty is a return of a bool (if empty true else false).

*/

#include <iostream>
#include <string>
#include "STACK.h"
void introduction();
void menuChooseStack();
void intStack();
void doubleStack();
void strStack();
using namespace std;
int main()
{
    introduction();
    int menuOption; bool again = false; 
    
    while (!again) {
        menuChooseStack();
        cin >> menuOption;
        switch (menuOption) {
        default:
            cout << "Invalid option";
            break;
        case 0:
            cout << "Exiting program";
            break;
        case 1:
            intStack();
            break;
        case 2:
            doubleStack();
            break;
        case 3:
            strStack();
            break;
        }
        again = menuOption == 0 ? true : false;
    }

}


void introduction() {
    cout << "\nThe assignment provides an opportunity to "
        << "\ncreate a stack template using the vector class vector<T> elements."
        << "\nProvided functionality include : push(), pop(), top(), clear(), empty();"
        << "\nboth popand top throw a handled exception if called when the stack is empty."
        << "\nempty is a return of a bool(if empty true else false).";

}


void menuChooseStack() {
    cout << "\nWhich stack did you want to choose:"
        << "\n(0) To Quit "
        << "\n(1) Int custom stack"
        << "\n(2) Double custom stack"
        << "\n(3) String custom stack\n";

}
void menuChooseStackOption(){
    cout << "\n\nWhich stack option did you want to choose:"
        << "\n(0) To quit Stack Option menu"
        << "\n(1) Push()"
        << "\n(2) Pop()"
        << "\n(3) Top()"
        << "\n(4) Clear()"
        << "\n(5) Empty()\n";

}

void intStack() {
    int val, menuOption; bool again = false; char rep; bool isCleared;
    STACK<int> customStackINT;

    while (!again) {
        menuChooseStackOption();
        cin >> menuOption;
        switch (menuOption) {
        default:
            cout << "Invalid option choose another Stack Menu option";
            break;
        case 0:
            cout << "Quitting to main menu";
            break;
        case 1:
            cout << "\nEnter element to push to top\n";
            cin >> val;
            customStackINT.push(to_string(val));
            cout << "Val ADDED\n";
            break;
        case 2:
            cout << "\nAttempting to pop the top\n";
            customStackINT.pop();
            break;
        case 3:
            try {
                if (customStackINT.empty() != true) {
                    val = stoi(customStackINT.top());
                    cout << "\nThe top is: " << val;
                }
                else { throw exception(); }
            }
            catch (exception e) { cout << "\nAn error was made today...\n"; }
            break;
        case 4:
            customStackINT.clear();
            cout << "\Stack is cleared: ";
            break;
        case 5:
            isCleared = customStackINT.empty();
            cout << "The stack is EMPTY: "<< boolalpha<< isCleared;
            break;
        }// end switch
        if (menuOption == 0) { again = true; }

    }

}
void doubleStack() {
    STACK<double> customStackD;
    
    double val; int menuOption; bool again = false; char rep; bool isCleared;

    while (!again) {
        menuChooseStackOption();
        cin >> menuOption;
        switch (menuOption) {
        default:
            cout << "Invalid option choose another Stack Menu option";
            break;
        case 0:
            cout << "Quitting to main menu";
            break;
        case 1:
            cout << "\nEnter element to push to top\n";
            cin >> val;
            customStackD.dpush(val);
            cout << "Val ADDED\n";
            break;
        case 2:
            cout << "\nAttempting to pop the top\n";
            customStackD.dpop();
                break;
        case 3:
            
            try {
                if (customStackD.dempty() == false) {
                    val = customStackD.dtop();
                    cout << "\nThe top is: " << val;
                }
                else { throw exception(); }
            }
            catch (exception e) { cout << "\nAn error was made today...\n"; }
            break;

        case 4:
            customStackD.dclear();
            cout << "\Stack is cleared: ";
            break;
        case 5:
            isCleared = customStackD.dempty();
            cout << "The stack is EMPTY: " << boolalpha << isCleared;
            break;
        }// end switch
        if (menuOption == 0) { again = true; }

    }




}
void strStack(){
    STACK<string> customStackSTR;

    string val; int menuOption; bool again = false; char rep; bool isCleared;

    while (!again) {
        menuChooseStackOption();
        cin >> menuOption;
        switch (menuOption) {
        default:
            cout << "Invalid option choose another Stack Menu option";
            break;
        case 0:
            cout << "Quitting to main menu";
            break;
        case 1:
            cout << "\nEnter element to push to top\n";
            cin.ignore();
            getline(cin,val);
            customStackSTR.push(val);
            cout << "Val ADDED\n";
            break;
        case 2:
                cout << "\nAttempting to pop the top\n";
                customStackSTR.pop();
                break;
        case 3:
            try {
                if (customStackSTR.empty() != true) {
                    val = customStackSTR.top();
                    cout << "\nThe top is: " << val;
                }
                else { throw exception(); }
            }
            catch (exception e) { cout << "\nAn error was made today...\n"; }
            break;


        case 4:
            customStackSTR.clear();
            cout << "\Stack is cleared: ";
            break;
        case 5:
            isCleared = customStackSTR.empty();
            cout << "The stack is EMPTY: " << boolalpha << isCleared;
            break;
        }// end switch
        if (menuOption == 0) { again = true; }

    }
}
