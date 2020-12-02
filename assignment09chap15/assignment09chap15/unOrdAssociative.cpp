#include "unOrdAssociative.h"



void unOrdAssociative::Unordered_setOptions() {
    unordered_set<int> uOS;
    int UOSinput;
    char again = 'y';
    while (again == 'y') {
        
        cout << "\nPlease insert an int: ";
        cin >> UOSinput;
        uOS.insert(UOSinput);
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }
    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To find an element \n(3)To get size of set" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto u : uOS) { cout << u << ' ' << endl; }
        }
        else if (opt1 == 2) {
            cout << "\nFind an element: ";
            cin >> UOSinput;

            cout << (uOS.count(UOSinput) ? " is in set" : " is not in set") << endl;
        }
        else if (opt1 == 3) {
            cout << "\nGet size of set: " << uOS.size();

        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }




   
}
void unOrdAssociative::Unordered_multisetOptions() {
    unordered_multiset<int> anotherSet;
    unordered_multiset<int> anotherSet2;
    anotherSet2.insert(1);   
    anotherSet2.insert(10);     
    anotherSet2.insert(20);




    int aSI;
    char again = 'y';
    while (again == 'y') {
        cout << "\nInsert an Int into the set: ";
        cin >> aSI;
        anotherSet.insert(aSI);

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To clear set \n(3)To swap set" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto a : anotherSet) { cout << a << ' '; }
        }
        else if (opt1 == 2) {
            cout << "\nCleared set";
            anotherSet.clear();
        }
        else if (opt1 == 3) {
            cout << "\nswapping with premade\n";
            anotherSet.swap(anotherSet2);
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }





}
void unOrdAssociative::Unordered_mapOptions() {
    unordered_map<int, int> intMaps;
    int int1, int2;
    char again = 'y';
    while (again == 'y') {
        cout << "Input ints into the map: ";
        cin >> int1 >> int2;
        intMaps[int1] = int2;
        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To see the bucket count \n(3)To see if empty " << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto i : intMaps) { cout << i.first << ' ' << i.second; }
        }
        else if (opt1 == 2) {
            cout << "\nThe bucket count is: " << intMaps.bucket_count();
        }
        else if (opt1 == 3) {
            cout << "Map empty status: " << boolalpha << intMaps.empty();
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }



    


}
void unOrdAssociative::Unordered_multimapOptions() {
    unordered_multimap<int, char> anotherMap2;
    unordered_multimap<int, char> swapper;

    int int1;
    char char1;

    char again = 'y';
    while (again == 'y') {
        cout << "\nInsert an int: ";
        cin >> int1;
        cout << "\nInsert a char: ";
        cin >> char1;
        anotherMap2.insert({ int1, char1 });

        cout << "\nAdd another (y/n): ";
        cin >> again;
    }

    swapper.insert({ 20, 'A' });
    swapper.insert({ 22, 'B' });
    swapper.insert({ 24, 'c' });

    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To swap to a premade map \n(3)To see the max size" << endl;
        cin >> opt1;

        if (opt1 == 1) {
            for (auto m : anotherMap2) { cout << m.first << ' ' << m.second << endl; }
        }
        else if (opt1 == 2) {

            cout << "\nSwap with premade unordered multimap";
            anotherMap2.swap(swapper);
        }
        else if (opt1 == 3) {
            cout << "\nThe max size is: " << anotherMap2.max_size();
        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }



}




/*
    int opt1 = 0;
    char anotherOption = 'y';
    while (anotherOption == 'y') {
        cout << "\n(1) To print\n(2)To \n(3)To " << endl;
        cin >> opt1;

        if (opt1 == 1) {

        }
        else if (opt1 == 2) {

        }
        else if (opt1 == 3) {

        }
        else {
            cout << "\nIncorrect input please choose another option";
        }
        cout << "\nWould you like another option(y/n): ";
        cin >> anotherOption;
    }

                queue<int> copyQ;
            copyQ = que1;
            while (!copyQ.empty()) {
                cout << copyQ.front() << ' ';
                copyQ.pop();
            }
*/