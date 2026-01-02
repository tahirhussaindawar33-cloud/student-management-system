# Student Management System

## Overview

This is a console-based **Student Management System** written in C++. It manages students, courses, marks, attendance, fees, and teachers in a single application. Data is stored in **CSV files** for easy Excel integration.

## Features

* **Student Module**: Add, View, Update, Delete student records.
* **Course Module**: Add, View, Update, Delete courses.
* **Marks Module**: Add, View, Update, Delete marks for students in courses.
* **Attendance Module**: Add, View, Update, Delete attendance records.
* **Fees Module**: Add, View, Update, Delete student fee records.
* **Teacher Module**: Add, View, Update, Delete teacher records.

## Installation

1. Clone the repository or download `main.cpp`.
2. Compile using a C++ compiler supporting C++11 or higher.

   ```
             g++ main.cpp -o StudentManagement
   ```
3. Run the executable:

   ```
   ./StudentManagement
   ```

## Usage

* Upon running, you will see a **main menu** with all modules.
* Navigate to any module to perform CRUD operations.
* Data is stored automatically in CSV files:

  * `students.csv`
  * `courses.csv`
  * `marks.csv`
  * `attendance.csv`
  * `fees.csv`
  * `teachers.csv`
* CSV files can be opened in Excel for reporting.

## Modules & Operations

### 1. Student Module