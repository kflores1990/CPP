#include "OrdContainers.h"

#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;


void OrdContainers::setOptions() {
    set <int> setOp;
    int inputSet;
    char again = 'y';
    while (again == 'y') {
        cout << "input int into set: ";
        cin >> inputSet;
        setOp.insert(inputSet);

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To see size of the set:\n(3)To see if empty and to clear" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto&& s : setOp) { cout << s << ' '; }

        }
        else if (opt1 == 2) {
            cout << "\nThe size is: " << setOp.size();

        }
        else if (opt1 == 3) {
            cout << "\nThe set is empty: " << boolalpha << setOp.empty() << endl;
            cout << "\nDid you want to clear the set(y/n): ";
            cin >> again;
            if (again == 'y') { setOp.clear(); }
            else { cout << "\nNot clearing set\n"; }
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }




    

}
void OrdContainers::multiSetOptions() {
    std::multiset<int> mSet;
    std::multiset<int> mSet2 = { 10, 20, 30, 40 };
    int msInput;
    char again = 'y';
    while (again == 'y') {
        cout << "\nadd to multiset: ";
        cin >> msInput;
        mSet.insert(msInput);

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To Swap with premade multiset\n(3)Erase value specified value" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto&& m : mSet) { cout << m << ' '; }
        }
        else if (opt1 == 2) {
            cout << "\nSwapped with premade multiset: ";
            mSet.swap(mSet2);
        }
        else if (opt1 == 3) {
            cout << "\nEnter specified value: ";
            cin >> msInput;
            std::multiset<int>::iterator it;
            it = mSet.find(msInput);
            mSet.erase(it);
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }



}
void OrdContainers::mapOptions() {
    std::map<int, string> mapOp;
    int mapInt;
    string mapString;
    char again = 'y';
    while (again == 'y') {
        cout << "Add an int to the map key: ";
        cin >> mapInt;
        cin.ignore();
        cout << "Add a string to the map value: ";
        getline(cin, mapString);


        mapOp.insert(pair<int, string>(mapInt, mapString));
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }
    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To see value at key location \n(3)To size of the map and the max size " << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto m : mapOp) { cout << m.first << ' ' << m.second << endl;}
        }
        else if (opt1 == 2) {
            cout << "Enter an int to view its key: ";
            cin >> mapInt;
            try {
                cout << "Value at key element: " << mapInt << " is: " << mapOp.at(mapInt);
            }
            catch (out_of_range e) {
                cout << "\nKey is not assigned in map";
            }
        }
        else if (opt1 == 3) {
            cout << "Size of the map: " << mapOp.size() << " : with the max size of: " << mapOp.max_size();
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }





}
void OrdContainers::multiMapOptions() {
    multimap<char, int> mMap;
    multimap<char, int> sMap;
    sMap.insert(std::pair<char, int>('a', 100));
    sMap.insert(std::pair<char, int>('z', 150));
    sMap.insert(std::pair<char, int>('b', 75));

    char mapC;
    int mapI;
    char again = 'y';
    while (again == 'y') {
        cout << "Add a char to the map value: ";
        cin >> mapC;
        cout << "Add an int to the map key: ";
        cin >> mapI;

        mMap.insert(pair<char, int>(mapC, mapI));

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To swap with premade map \n(3)To clear map" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto m : mMap) { cout << m.first << ' ' << m.second << endl; }
        }
        else if (opt1 == 2) {
            cout << "\nSwapping with a premade map: " << endl;
            mMap.swap(sMap);
        }
        else if (opt1 == 3) {
            cout << "\ncleared map\n";

            mMap.clear();

        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }




    


}


