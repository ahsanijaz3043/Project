#include "record.h"

void addrecord() {
    information boss;
    cout << "Enter cnic: "; cin >> boss.cnic;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, boss.name);
    cout << "Enter Address: ";
    getline(cin, boss.address);
    cout << "Enter age: "; cin >> boss.age;
    
    ofstream inform("Record.txt", ios::app);
    if (!inform) {
        cout << "Invalid file! \n";
        return;
    }

    inform << boss.cnic << "," << boss.name << "," << boss.address << "," << boss.age << endl;
    inform.close();
    cout << "Enter Record Successfully \n";
}

void showdata() {
    ifstream inform("Record.txt");
    if (!inform) {
        cout << "Invalid File!\n";
        return;
    }
    string line;
    while (getline(inform, line)) {
        cout << line << endl;
    }
    inform.close();
    cout << "Show Data Successfully!\n";
}

void searchRecord() {
    information boss;
    string cnic, line;
    cout << "Enter the cnic: "; cin >> cnic;
    ifstream inform("Record.txt");
    if (!inform) {
        cout << "Invalid file! \n";
        return;
    }
    bool found = false;
    while (getline(inform, line)) {
        if (line.find(cnic) != string::npos) {
            cout << line;
            found = true;
        }
    }
    inform.close();
    if (found) {
        cout << "Found Record:\n";
    } else {
        cout << "Not found Record";
    }
}

void UpdateRecord() {
    string cnic, line;
    cout << "enter cnic:"; cin >> cnic;
    ifstream inform("Record.txt");
    ofstream temp("tem.txt");
    if (!inform || !temp) {
        cout << "Not Open file!\n";
        return;
    }
    information boss;
    bool found = false;
    while (getline(inform, line)) {
        if (line.find(cnic) != string::npos) {
            cout << "Change Data:\n";
            cout << "Enter CNIC:";
            cin.ignore();
            getline(cin, boss.cnic);
            cout << "Enter Name:";
            getline(cin, boss.name);
            cout << "Enter address:";
            getline(cin, boss.address);
            cout << "Enter age:";
            cin >> boss.age;
            temp << boss.cnic << "," << boss.name << "," << boss.address << "," << boss.age << endl;
            found = true;
        } else {
            temp << line << endl;
        }
    }
    inform.close();
    temp.close();
    remove("Record.txt");
    rename("tem.txt", "Record.txt");
    if (found) {
        cout << "Update Successfully!\n";
    } else {
        cout << "Not Found Record!";
    }
}

void deleteData() {
    information boss;
    ifstream inform("Record.txt");
    ofstream temp("tem.txt");
    string cnic, line;
    cout << "Enter CNIC: "; cin >> cnic;
    bool found = false;
    while (getline(inform, line)) {
        if (line.find(cnic) != string::npos) {
            found = true;
        } else {
            temp << line << endl;
        }
    }
    inform.close();
    temp.close();
    remove("Record.txt");
    rename("tem.txt", "Record.txt");
    if (found) {
        cout << "Delete Data Successfully! \n";
    } else {
        cout << "Not found Data!";
    }
}