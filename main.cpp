#include "record.h"

int main() {
    int choice;
    do {
        cout << "\n*Record Menu*\n";
        cout << "1: Add record\n";
        cout << "2: Show all Record \n";
        cout << "3: Search Data \n";
        cout << "4: Update Data \n";
        cout << "5: Delete Data \n";
        cout << "6: Exit!\n";
        cout << "Enter Your Choice:"; cin >> choice;
        
        switch (choice) {
            case 1:
                addrecord();
                break;
            case 2:
                showdata();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                UpdateRecord();
                break;
            case 5:
                deleteData();
                break;
            case 6:
                cout << "Thank You For Exiting Program!";
                break;
            default:
                cout << "Invalid Number:";
        }
    } while (choice != 6);
    
    return 0;
}