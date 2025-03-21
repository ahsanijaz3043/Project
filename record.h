#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct information {
    string cnic;
    string name;
    string address;
    int age;
};

// Function Prototypes
void addrecord();
void showdata();
void searchRecord();
void UpdateRecord();
void deleteData();

#endif