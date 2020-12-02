/*Kyle Flores chap15 assignment 09. 
This program demonstrates different containers, iterators, algorithms, and the containers used are:
sequence containers 
                -> array, deque, forward-list, list, vector
ordered associative containers 
                ->set, multiset, map, multimap
unordered associative containers 
                -> unordered; set, multiset, map, multimap
container adapters 
                -> stack, queue, priority_queue
*/

#include <iostream>
#include "SeqContainers.h"
#include "containerAdapters.h"
#include "OrdContainers.h"
#include "unOrdAssociative.h"
using namespace std;
void introduction();
void menuOptions();
void menuSequenceContainers();
void menuOrderedAssociativeContainers();
void menuUnorderedAssociativeContainers();
void menuContainerAdapters();

int main()
{
    introduction();
    char again = 'y';
    while (again == 'y') {
        menuOptions();
        int optionSelection1, optionSelection2;

        cin >> optionSelection1;
        if (optionSelection1 == 1) {
            menuSequenceContainers();
            SeqContainers sq1;
            cin >> optionSelection2;
            switch (optionSelection2)
            {
            case 1:
                sq1.arrayOptions();
                break;
            case 2:
                sq1.dequeOptions();
                break;
            case 3:
                sq1.forwardListOptions();
                break;
            case 4:
                sq1.listOptions();
                break;
            case 5:
                sq1.vectorOptions();
                break;
            default:
                cout << "Invalid option";
                break;
            }

        }
        else if (optionSelection1 == 2) {
            menuOrderedAssociativeContainers();
            cin >> optionSelection2;
            OrdContainers oc1;
            switch (optionSelection2)
            {
            case 1:
                oc1.setOptions();
                break;
            case 2:
                oc1.multiSetOptions();
                break;
            case 3:
                oc1.mapOptions();
                break;
            case 4:
                oc1.multiMapOptions();
                break;
            default:
                cout << "Invalid option";
                break;
            }
        }
        else if (optionSelection1 == 3) {
            menuUnorderedAssociativeContainers();
            cin >> optionSelection2;
            unOrdAssociative uo1;
            switch (optionSelection2)
            {
            case 1:
                uo1.Unordered_setOptions();
                break;
            case 2:
                uo1.Unordered_multisetOptions();
                break;
            case 3:
                uo1.Unordered_mapOptions();
                break;
            case 4:
                uo1.Unordered_multimapOptions();
                break;
            case 5:
                break;
            default:
                cout << "Invalid option";
                break;
            }
        }
        else if (optionSelection1 == 4) {
            menuContainerAdapters();
            cin >> optionSelection2;
            containerAdapters ca1;
            switch (optionSelection2)
            {
            case 1:
                ca1.stackOptions();
                break;
            case 2:
                ca1.queueOptions();
                break;
            case 3:
                ca1.priority_queueOptions();
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout << "Invalid option";
                break;
            }

        }

        cout << "\nWould you like another menu option(y/n): ";
        cin >> again;

    }
}

//----------------------MENU OPTIONS-----------------//
void introduction() {
    cout << "This program is assignment-09 and demonstrates some of the containers in c++";
}
void menuOptions() {
    cout << "\nPlease select the following option enter 0 to quit: "
        << "\n(1) Sequence Containers"
        << "\n(2) Ordered Associative Containers"
        << "\n(3) Unordered Associative Containers"
        << "\n(4) Container Adapters\n";

}

//----------1 Sequence Containers-----------//
void menuSequenceContainers(){
    cout << "\nPlease select sub menu option\n"
        << "(1) Array\n"
        << "(2) Deque\n"
        << "(3) Forward - list\n" 
        << "(4) List\n"  
        << "(5) Vector\n";
    
}
//----------2 Ordered Associative Containers-----------//
void menuOrderedAssociativeContainers() {
    cout << "\nPlease select sub menu option\n" 
        << "(1) Set\n"
        << "(2) Multiset\n"
        << "(3) Map\n"
        << "(4) Multimap\n";

}
//----------3 Unordered Associative Containers-----------//
void menuUnorderedAssociativeContainers() {
    cout << "\nPlease select sub menu option\n"
        << "(1) Unordered_set\n"
        << "(2) Unordered_multiset\n"
        << "(3) Unordered_map\n"
        << "(4) Unordered_multimap\n";
    
}
//----------4 Container Adapters-----------//
void menuContainerAdapters() {
    cout << "\nPlease select sub menu option\n"
        << "(1) Stack\n"
        << "(2) Queue\n"
        << "(3) Priority_queue\n";
}



