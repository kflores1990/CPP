#include "SeqContainers.h"
#include <iostream>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

using namespace std;


void SeqContainers::arrayOptions() {
    array <int, 5> arr;
    cout << "Please fill the array with 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To reverse the Array\n(3)To print only odds\n";
        cin >> opt1;

        if (opt1 == 1) {
            for (auto&& a : arr) {
                cout << a << ' ';
            }
        }
        else if (opt1 == 2) {
            cout << "Reverse array: ";
            for (int i = arr.size() - 1; i >= 0; i--) {
                cout << arr[i] << ' ';
            }
        }
        else if (opt1 == 3) {
            cout << "Odds only: ";
            for (auto&& a : arr) {
                if ((a % 2) != 0) { cout << a << ' '; }
            }
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }

    

    

    
    
}
void SeqContainers::dequeOptions() {
    deque<int> deq;
    cout << "Add to deque: \n";
    char again = 'y';
    int dInput;
    while (again == 'y') {
        cout << "Enter an Int: ";
        cin >> dInput;
        deq.push_back(dInput);
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To total the values\n(3)Push to front" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (int d : deq) {
                cout << d << ' ';
            }
        }
        else if (opt1 == 2) {
            cout << "\nTotal of deque values are: ";
            int total = 0;
            for (auto&& d : deq) {
                total += d;
            }
            cout << total;
        }
        else if (opt1 == 3) {
            cout << "\nInsert int at front of deque\n";
            cin >> dInput;
            deq.push_front(dInput);
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }






}
void SeqContainers::forwardListOptions(){
    forward_list<int> flist;
    cout << "\nInsert ints into forward list:\n ";
    int Linput;
    char again = 'y';
    while (again == 'y') {
        cout << "Please enter an int: ";
        cin >> Linput;
        flist.push_front(Linput);
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To show even numbers\n(3)To sort" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto&& f : flist) { cout << f << ' '; }
        }
        else if (opt1 == 2) {
            cout << "\nShowing even numbers: \n";
            for (int f : flist) {
                if ((f % 2) == 0) {
                    cout << f << ' ';
                }
            }
        }
        else if (opt1 == 3) {
            cout << "\nList sorted: ";
            flist.sort();
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }






    

}
void SeqContainers::listOptions() {
    list<char> charList;
    char cVar;
    char again = 'y';
    while (again == 'y') {
        cout << "Insert a char: ";
        cin >> cVar;
        charList.push_back(cVar);

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To pop front\n(3)To remove duplicates" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto&& c : charList) {
                cout << c << ' ';
            }
        }
        else if (opt1 == 2) {
            cout << "\nPop front of list\n";
            charList.pop_front();
        }
        else if (opt1 == 3) {
            cout << "\nRemoving duplicate values: ";
            charList.unique();
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }

}
void SeqContainers::vectorOptions() {
    vector<int> vec;
    int vecInt;

    char again = 'y';
    while (again == 'y') {
        cout << "Insert an int: ";
        cin >> vecInt;
        vec.push_back(vecInt);

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }


    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To Pop back val\n(3)To double the vector size" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto&& v : vec) { cout << v << ' '; }
        }
        else if (opt1 == 2) {
            cout << "\nPop the end of the vec: \n";
            vec.pop_back();
        }
        else if (opt1 == 3) {
            cout << "Double vector size\nCurrent: " << vec.size();
            vec.resize((vec.size() * 2));
            cout << "\nNew size: " << vec.size();

        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }












}



