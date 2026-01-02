#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string className;
    string section;
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);
    cout << "Enter ID: "; cin >> s.id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, s.name);
    cout << "Enter Age: "; cin >> s.age;
    cin.ignore();
    cout << "Enter Class: "; getline(cin, s.className);
    cout << "Enter Section: "; getline(cin, s.section);
    file << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
    file.close();
    cout << "Student Added!\n";
}

void viewStudents() {
    ifstream file("students.txt");
    Student s;
    cout << "ID Name Age Class Section\n";
    while(file >> s.id >> s.name >> s.age >> s.className >> s.section) {
        cout << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
    }
    file.close();
}

void updateStudent() {
    int id; 
    cout << "Enter ID to update: "; cin >> id;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;
    while(file >> s.id >> s.name >> s.age >> s.className >> s.section) {
        if(s.id == id) {
            found = true;
            cin.ignore();
            cout << "Enter new Name: "; getline(cin, s.name);
            cout << "Enter new Age: "; cin >> s.age;
            cin.ignore();
            cout << "Enter new Class: "; getline(cin, s.className);
            cout << "Enter new Section: "; getline(cin, s.section);
        }
        temp << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
    }
    file.close(); temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found) cout << "Student Updated!\n";
    else cout << "ID Not Found!\n";
}

void deleteStudent() {
    int id; 
    cout << "Enter ID to delete: "; cin >> id;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;
    while(file >> s.id >> s.name >> s.age >> s.className >> s.section) {
        if(s.id != id) temp << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found) cout << "Student Deleted!\n";
    else cout << "ID Not Found!\n";
}