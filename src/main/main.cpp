#include <iostream>
#include "student.h"
#include "course.h"
#include "marks.h"
#include "attendance.h"
#include "fees.h"
#include "teacher.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Student Management\n";
        cout << "2. Course Management\n";
        cout << "3. Marks Management\n";
        cout << "4. Attendance Management\n";
        cout << "5. Fee Management\n";
        cout << "6. Teacher Management\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int subChoice;
        switch(choice) {
            case 1:
                cout << "\n1. Add Student\n2. View Students\n3. Update Student\n4. Delete Student\nEnter choice: ";
                cin >> subChoice;
                if(subChoice == 1) addStudent();
                else if(subChoice == 2) viewStudents();
                else if(subChoice == 3) updateStudent();
                else if(subChoice == 4) deleteStudent();
                break;

            case 2:
                cout << "\n1. Add Course\n2. View Courses\n3. Update Course\n4. Delete Course\nEnter choice: ";
                cin >> subChoice;
                if(subChoice == 1) addCourse();
                else if(subChoice == 2) viewCourses();
                else if(subChoice == 3) updateCourse();
                else if(subChoice == 4) deleteCourse();
                break;

            case 3:
                cout << "\n1. Add Marks\n2. View Marks\n3. Update Marks\n4. Delete Marks\nEnter choice: ";
                cin >> subChoice;
                if(subChoice == 1) addMark();
                else if(subChoice == 2) viewMarks();
                else if(subChoice == 3) updateMark();
                else if(subChoice == 4) deleteMark();
                break;

            case 4:
                cout << "\n1. Add Attendance\n2. View Attendance\n3. Update Attendance\n4. Delete Attendance\nEnter choice: ";
                cin >> subChoice;
                if(subChoice == 1) addAttendance();
                else if(subChoice == 2) viewAttendance();
                else if(subChoice == 3) updateAttendance();
                else if(subChoice == 4) deleteAttendance();
                break;

            case 5:
                cout << "\n1. Add Fee\n2. View Fees\n3. Update Fee\n4. Delete Fee\nEnter choice: ";
                cin >> subChoice;
                if(subChoice == 1) addFee();
                else if(subChoice == 2) viewFees();
                else if(subChoice == 3) updateFee();
                else if(subChoice == 4) deleteFee();
                break;

            case 6:
                cout << "\n1. Add Teacher\n2. View Teachers\n3. Update Teacher\n4. Delete Teacher\nEnter choice: ";
                cin >> subChoice;
                if(subChoice == 1) addTeacher();
                else if(subChoice == 2) viewTeachers();
                else if(subChoice == 3) updateTeacher();
                else if(subChoice == 4) deleteTeacher();
                break;
        }
    } while(choice != 0);

    return 0;
}