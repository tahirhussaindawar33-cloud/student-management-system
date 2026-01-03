#include <iostream>
#include <fstream>
#include <string>
#include "fees.h"
using namespace std;

struct Fee {
    int studentID;
    float amount;
    string status; // Paid / Unpaid
};

void addFee() {
    Fee f;
    ofstream file("fees.txt", ios::app);
    cout << "Enter Student ID: "; cin >> f.studentID;
    cout << "Enter Fee Amount: "; cin >> f.amount;
    cin.ignore();
    cout << "Enter Status (Paid/Unpaid): "; getline(cin, f.status);
    file << f.studentID << " " << f.amount << " " << f.status << endl;
    file.close();
    cout << "Fee Record Added!\n";
}

void viewFees() {
    ifstream file("fees.txt");
    Fee f;
    cout << "StudentID Amount Status\n";
    while(file >> f.studentID >> f.amount >> f.status) {
        cout << f.studentID << " " << f.amount << " " << f.status << endl;
    }
    file.close();
}

void updateFee() {
    int studentID;
    cout << "Enter Student ID to Update: "; cin >> studentID;
    ifstream file("fees.txt");
    ofstream temp("temp.txt");
    Fee f;
    bool found = false;
    while(file >> f.studentID >> f.amount >> f.status) {
        if(f.studentID == studentID) {
            found = true;
            cout << "Enter new Fee Amount: "; cin >> f.amount;
            cin.ignore();
            cout << "Enter new Status (Paid/Unpaid): "; getline(cin, f.status);
        }
        temp << f.studentID << " " << f.amount << " " << f.status << endl;
    }
    file.close(); temp.close();
    remove("fees.txt");
    rename("temp.txt", "fees.txt");
    if(found) cout << "Fee Record Updated!\n";
    else cout << "Student Not Found!\n";
}

void deleteFee() {
    int studentID;
    cout << "Enter Student ID to Delete: "; cin >> studentID;
    ifstream file("fees.txt");
    ofstream temp("temp.txt");
    Fee f;
    bool found = false;
    while(file >> f.studentID >> f.amount >> f.status) {
        if(f.studentID != studentID) temp << f.studentID << " " << f.amount << " " << f.status << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("fees.txt");
    rename("temp.txt", "fees.txt");
    if(found) cout << "Fee Record Deleted!\n";
    else cout << "Student Not Found!\n";
}