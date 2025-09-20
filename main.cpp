#include <bits/stdc++.h>
#include "Student.h"
#include "DSA/Sorting.h"
#include "DSA/Search.h"
#include "Globals.h"

using namespace std;

//extern vector<Student> students;

void addStudent();
void deleteStudent();
void updateStudent();
void displayAll();
void searchStudent();
void sortStudents();
void displayTopper();
void filterStudents();
void saveToFile();
void loadFromFile();

//  function to get a valid menu choice (0-8)
int getValidChoice()
{
    int choice;
    while (true)
    {
        std::cout << "Enter choice: ";
        if (std::cin >> choice) // successfully read an integer
        {
            if (choice >= 0 && choice <= 8)
                return choice;
            else
                std::cout << "Invalid choice – enter a number between 0 and 8.\n";
        }
        else
        {
            std::cout << "Invalid input – please enter a number.\n";
            std::cin.clear(); // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        }
    }
}



int main()
{
    loadFromFile();

    while (true)
    {
        cout << "\n==== Student Management System ====\n"
             << "1. Add Student\n"
             << "2. Delete Student\n"
             << "3. Update Student\n"
             << "4. Display All Students\n"
             << "5. Search Student\n"
             << "6. Sort Students (with marks range)\n"
             << "7. Display Topper\n"
             << "8. Filter Students by Marks Range\n"
             << "0. Exit\n";

        int choice = getValidChoice();

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            displayAll();
            break;
        case 5:
            searchStudent();
            break;
        case 6:
            sortStudents();
            break;
        case 7:
            displayTopper();
            break;
        case 8:
            filterStudents();
            break;
        case 0:
            saveToFile();
            return 0;
        }
    }
}
