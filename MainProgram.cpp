#include "CoreClasses.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    SystemManager system;
    int choice;

    system.loadData();
    
    cout << "This version works!! 4.54" << endl << endl;

    do
    {
        cout << endl;
        
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
                system.searchInstrumentByBrand();
                break;
            case 9:
                system.searchInstrumentByModel();
                break;
            case 10:
                system.displayWhoRentedWhat();
                break;
            case 11:
                system.sortInstrumentsByPrice();
                break;
            case 12:
                system.saveData();
                cout << "Bye Bye!" << endl;
                break;
            }
    } while (choice != 12);
    return 0;
}



