#include <iostream>
#include <fstream>
#include "marks.h"
using namespace std;

struct Mark {
    int studentID;
    int courseID;
    float marks;
};

void addMark() {
    Mark m;
    ofstream file("marks.txt", ios::app);
    cout << "Enter Student ID: "; cin >> m.studentID;
    cout << "Enter Course ID: "; cin >> m.courseID;
    cout << "Enter Marks: "; cin >> m.marks;
    file << m.studentID << " " << m.courseID << " " << m.marks << endl;
    file.close();
    cout << "Marks Added!\n";
}

void viewMarks() {
    ifstream file("marks.txt");
    Mark m;
    cout << "StudentID CourseID Marks\n";
    while(file >> m.studentID >> m.courseID >> m.marks) {
        cout << m.studentID << " " << m.courseID << " " << m.marks << endl;
    }
    file.close();
}

void updateMark() {
    int studentID, courseID;
    cout << "Enter Student ID: "; cin >> studentID;
    cout << "Enter Course ID: "; cin >> courseID;
    ifstream file("marks.txt");
    ofstream temp("temp.txt");
    Mark m;
    bool found = false;
    while(file >> m.studentID >> m.courseID >> m.marks) {
        if(m.studentID == studentID && m.courseID == courseID) {
            found = true;
            cout << "Enter new Marks: "; cin >> m.marks;
        }
        temp << m.studentID << " " << m.courseID << " " << m.marks << endl;
    }
    file.close(); temp.close();
    remove("marks.txt");
    rename("temp.txt", "marks.txt");
    if(found) cout << "Marks Updated!\n";
    else cout << "Record Not Found!\n";
}

void deleteMark() {
    int studentID, courseID;
    cout << "Enter Student ID: "; cin >> studentID;
    cout << "Enter Course ID: "; cin >> courseID;
    ifstream file("marks.txt");
    ofstream temp("temp.txt");
    Mark m;
    bool found = false;
    while(file >> m.studentID >> m.courseID >> m.marks) {
        if(m.studentID != studentID || m.courseID != courseID) {
            temp << m.studentID << " " << m.courseID << " " << m.marks << endl;
        } else found = true;
    }
    file.close(); temp.close();
    remove("marks.txt");
    rename("temp.txt", "marks.txt");
    if(found) cout << "Marks Deleted!\n";
    else cout << "Record Not Found!\n";
}