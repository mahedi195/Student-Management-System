# Student Management System (C++)

This is a **console-based Student Management System** implemented in C++ using DSA concepts like arrays, searching, and sorting. The system supports persistent storage and sequential student IDs.


## used DSA

 **Searching**

-Linear Search by Name ,Binary Search by Marks:
-Insertion Sort by Name , Insertion Sort by Marks
-

## Features

1. **Add Student**
   - Automatically assigns sequential IDs.
   - Enter Name and Marks.

2. **Delete Student**
   - Delete student by ID.
   - Next ID is automatically adjusted.

3. **Update Student**
   - Update Name and Marks by ID.

4. **Display All Students**
   - Displays in a **table format** (Name, ID, Marks).

5. **Search Student**
   - Search by Name or Marks.
   - Displays "Invalid name/marks" if not found.
   -Work with partial matches.
   -Be case-insensitive.(mahedi= Mahedi).
   -Display all matching students.(input-> Mahedi , output: Mahedi hasan and Mahedi Emon )

6. **Sort Students**
   - Enter a marks range.
   - Sort filtered students by Name or Marks.

7. **Display Topper**
   - Shows student(s) with the highest marks.

8. **Filter Students by Marks Range**
   - Displays students within a given range.

9. **Persistent Storage**
   - Data is saved to `students_data.txt` on exit.
   - Data is loaded at program start.

---

## Folder Structure

studentManagement/
├── main.cpp
├── student.cpp
├── Student.h
├── utils.h
├── DSA/
│ ├── Sorting.h
│ └── Search.h
├── students_data.txt # generated automatically after first run
└── studentManagement.exe

##
**File I/O (Persistence)

-saveToFile() writes students to students_data.txt
-loadFromFile() reads students on program startup




## Run project


1. Open Command Prompt in the project folder:


cd "C:\Users\user\Desktop\student management system\studentManagement"
g++ main.cpp student.cpp Globals.cpp -I. -o studentManagement.exe
studentManagement.exe
