#include "CoreClasses.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    SystemManager system;
    int choice;

    cout << "________________________________________________________________________" << endl << endl;
    cout << "\tCCS0015L - Data Structures and Algorithms (LAB)" << endl;
    cout << "\t Final Project: Musical Instrument Rental System" << endl;
    cout << "\t Members:  Balleta, Chang, Salanguit, Vales" << endl;
    cout << "________________________________________________________________________" << endl;    
    system.loadData();
    do{
        system.displayMenu();
        cout << endl << "Type in your choice: ";
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
                system.displayWaitingQueue();
                break;
            case 13:
                system.saveData();
                cout << "Bye Bye!" << endl;
                break;
            default:
                cin.clear();
                cin.ignore(1000, '\n');
                ::system("cls");
                cout << "------------------------------------" << endl << endl;
                cout << "Invalid choice. Please try again." << endl << endl;
                cout << "------------------------------------" << endl << endl;
                break;
            }
    } while (choice != 13);
    return 0;
}



