#include "CoreClasses.h"
#include <iostream>
using namespace std;

int main(){
    SystemManager system;
    int choice;
    
    do
    {
        system.displayMenu();
        cout << "Type in your choice: ";
        cin >> choice;
        cin.ignore();
         switch (choice)
            {
            case 1:
                system.addInstrument();
                break;
            case 2:
                system.addCustomer();
                break;
            case 3:
                system.rentInstrument();
                break;
            case 4:
                system.returnInstrument();
                break;
            case 5:
                system.displayAvailableInstruments();
                break;
            case 6:
                system.displayAllRentals();
                break;
            case 7:
                system.updateCustomerInfo();
                break;
            case 8:
                cout << "Bye Bye!" << endl;
                break;
            default:
                cout << "Invalid Input." << endl;
                break;
            }
    } while (choice != 8);
    return 0;
}



