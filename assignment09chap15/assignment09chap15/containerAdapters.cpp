#include "containerAdapters.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
void containerAdapters::stackOptions() {
    stack<int> stInts;
    int sI;

    char again = 'y';
    while (again == 'y') {
        cout << "\nInsert an int into the stack: ";
        cin >> sI;
        stInts.push(sI);

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To pop top\n(3)To view top" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            stack<int> copyStack;
            copyStack = stInts;
            while (!copyStack.empty()) {
                cout << copyStack.top() << ' ';
                copyStack.pop();
            }
        }
        else if (opt1 == 2) {
            cout << "\nPopped top";
            stInts.pop();

        }
        else if (opt1 == 3) {
            cout << "\nThe top is: ";
            cout << stInts.top();

        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }



    
    
}
void containerAdapters::queueOptions() {
    queue<int> que1;
    int int1;

    char again = 'y';
    while (again == 'y') {
        cout << "\nEnter an Int: ";
        cin >> int1;

        que1.push(int1);
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To see last element\n(3)To check if empty" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            queue<int> copyQ;
            copyQ = que1;
            while (!copyQ.empty()) {
                cout << copyQ.front() << ' ';
                copyQ.pop();
            }
        }
        else if (opt1 == 2) {
            cout << "\nLast element: "<<  que1.back();

        }
        else if (opt1 == 3) {
            cout << "\nThe queue is empty: " << boolalpha << que1.empty();

        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }







}
void containerAdapters::priority_queueOptions() {
    priority_queue <int> last1;
    int int1;
    char again = 'y';
    while (again == 'y') {
        cout << "\nEnter an int: ";
        cin >> int1;
        last1.push(int1);
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }
    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To see size\n(3)To pop top" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            priority_queue<int> copyQ;
            copyQ = last1;
            while (!copyQ.empty()) {
                cout << copyQ.top() << ' ';
                copyQ.pop();
            }
        }
        else if (opt1 == 2) {
            cout << "\nThe size of the priority queue: " << last1.size() << endl;

        }
        else if (opt1 == 3) {
            cout << "\nPopped top element" << endl;
            last1.pop();
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }




    

}







