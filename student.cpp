#include <bits/stdc++.h>
#include "Student.h"
#include "DSA/Sorting.h"
#include "DSA/Search.h"
#include <fstream>
#include <sstream>
#include "Globals.h"




using namespace std;

//extern vector<Student> students;
//static int nextId = 1;   //  next valid ID

// ================= Helper Functions =================
bool isValidName(const string &name)
{
    if(name.empty()) return false;
    for(char c : name)
        if(!isalpha(c) && c != ' ') return false;
    return true;
}

bool isValidNumber(const string &s)
{
    if(s.empty()) return false;
    int dotCount = 0;
    for(char c : s)
    {
        if(c == '.')
        {
            dotCount++;
            if(dotCount > 1) return false;
        }
        else if(!isdigit(c)) return false;
    }
    return true;
}

// ================== Core Functions ==================
void addStudent()
{
    cout << "Next ID must be: " << nextId << "\n";

    int id;
    while(true)
    {
        string input;
        cout << "Enter ID: ";
        cin >> input;
        if(!isValidNumber(input))
        {
            cout << "Invalid input – please enter a number.\n";
            continue;
        }
        id = stoi(input);
        if(id != nextId)
        {
            cout << "Invalid ID – must be " << nextId << "\n";
            continue;
        }
        break;
    }

    cin.ignore(); // remove leftover newline

    string name;
    while(true)
    {
        cout << "Enter Name: ";
        getline(cin, name);
        if(!isValidName(name))
        {
            cout << "Invalid input – name must contain letters only.\n";
            continue;
        }
        break;
    }

    double marks;
    while(true)
    {
        string input;
        cout << "Enter Marks: ";
        cin >> input;
        if(!isValidNumber(input))
        {
            cout << "Invalid input – please enter a number.\n";
            continue;
        }
        marks = stod(input);
        if(marks < 0 || marks > 100)
        {
            cout << "Marks must be between 0 and 100.\n";
            continue;
        }
        break;
    }

    Student s;
    s.id = id;
    s.name = name;
    s.marks = marks;
    students.push_back(s);
    nextId++;
    cout << "Student added successfully!\n";
}

void deleteStudent()
{
    int id;
    while(true)
    {
        string input;
        cout << "Enter ID to delete: ";
        cin >> input;
        if(!isValidNumber(input))
        {
            cout << "Invalid input – please enter a number.\n";
            continue;
        }
        id = stoi(input);
        break;
    }

    auto it = find_if(students.begin(), students.end(),
                      [&](const Student& s)
    {
        return s.id == id;
    });
    if (it != students.end())
    {
        students.erase(it);
        cout << "Student deleted.\n";
    }
    else cout << "Invalid ID – not found.\n";

    // recompute nextId after deletion
    int maxId = 0;
    for (auto &s : students)
        if (s.id > maxId) maxId = s.id;
    nextId = maxId + 1;
}

void updateStudent()
{
    int id;
    while(true)
    {
        string input;
        cout << "Enter ID to update: ";
        cin >> input;
        if(!isValidNumber(input))
        {
            cout << "Invalid input – please enter a number.\n";
            continue;
        }
        id = stoi(input);
        break;
    }

    auto it = find_if(students.begin(), students.end(),
                      [&](const Student& s)
    {
        return s.id == id;
    });
    if (it != students.end())
    {
        cin.ignore(); // remove leftover newline

        string name;
        while(true)
        {
            cout << "Enter new Name: ";
            getline(cin, name);
            if(!isValidName(name))
            {
                cout << "Invalid input – name must contain letters only.\n";
                continue;
            }
            it->name = name;
            break;
        }

        double marks;
        while(true)
        {
            string input;
            cout << "Enter new Marks: ";
            cin >> input;
            if(!isValidNumber(input))
            {
                cout << "Invalid input – please enter a number.\n";
                continue;
            }
            marks = stod(input);
            if(marks < 0 || marks > 100)
            {
                cout << "Marks must be between 0 and 100.\n";
                continue;
            }
            it->marks = marks;
            break;
        }
        cout << "Student updated.\n";
    }
    else cout << "Invalid ID – not found.\n";
}

void displayAll()
{
    if(students.empty())
    {
        cout << "No students.\n";
        return;
    }
    cout << left << setw(20) << "Name"
         << setw(8)  << "ID"
         << setw(8)  << "Marks" << "\n";
    cout << string(36,'-') << "\n";
    for(const auto &s : students)
        cout << left << setw(20) << s.name
             << setw(8)  << s.id
             << setw(8)  << s.marks << "\n";
}

void displayAll(const vector<Student>& list)
{
    if(list.empty())
    {
        cout << "No students.\n";
        return;
    }
    cout << left << setw(20) << "Name"
         << setw(8)  << "ID"
         << setw(8)  << "Marks" << "\n";
    cout << string(36,'-') << "\n";
    for(const auto &s : list)
        cout << left << setw(20) << s.name
             << setw(8)  << s.id
             << setw(8)  << s.marks << "\n";
}

void searchStudent()
{
    cout << "1. Search by Name\n2. Search by Marks\nEnter option: ";
    int option;
    cin >> option;
    if(option == 1)
    {
        cin.ignore();
        string name;
        getline(cin, name);
        int idx = linearSearchByName(students, name);
        if(idx != -1) displayAll(vector<Student> {students[idx]});
        else cout << "Invalid name – not found.\n";
    }
    else if(option == 2)
    {
        string input;
        cout << "Enter marks to search: ";
        cin >> input;
        if(!isValidNumber(input))
        {
            cout << "Invalid input – must be a number.\n";
            return;
        }
        double marks = stod(input);
        insertionSortByMarks(students);
        int idx = binarySearchByMarks(students, marks);
        if(idx != -1) displayAll(vector<Student> {students[idx]});
        else cout << "Invalid marks – not found.\n";
    }
    else cout << "Invalid option.\n";
}

void sortStudents()
{
    double low, high;
    while(true)
    {
        string input1, input2;
        cout << "Enter marks range (low high): ";
        cin >> input1 >> input2;
        if(!isValidNumber(input1) || !isValidNumber(input2))
        {
            cout << "Invalid input – must be numbers.\n";
            continue;
        }
        low = stod(input1);
        high = stod(input2);
        break;
    }

    vector<Student> filtered;
    for(auto &s: students)
        if(s.marks >= low && s.marks <= high)
            filtered.push_back(s);

    if(filtered.empty())
    {
        cout << "No students in that range.\n";
        return;
    }

    cout << "1. Sort by Name\n2. Sort by Marks\nEnter option: ";
    int option;
    cin >> option;
    if(option == 1) insertionSortByName(filtered);
    else if(option == 2) insertionSortByMarks(filtered);
    else
    {
        cout << "Invalid option.\n";
        return;
    }

    displayAll(filtered);
}

void displayTopper()
{
    if(students.empty())
    {
        cout << "No students.\n";
        return;
    }
    auto top = max_element(students.begin(), students.end(),
                           [](const Student &a,const Student &b)
    {
        return a.marks < b.marks;
    });
    cout << "Topper:\n";
    displayAll(vector<Student> {*top});
}

void filterStudents()
{
    double low, high;
    while(true)
    {
        string input1, input2;
        cout << "Enter marks range (low high): ";
        cin >> input1 >> input2;
        if(!isValidNumber(input1) || !isValidNumber(input2))
        {
            cout << "Invalid input – must be numbers.\n";
            continue;
        }
        low = stod(input1);
        high = stod(input2);
        break;
    }

    vector<Student> filtered;
    for(auto &s: students)
        if(s.marks >= low && s.marks <= high)
            filtered.push_back(s);
    if(filtered.empty()) cout << "No students in that range.\n";
    else displayAll(filtered);
}

// ================ File I/O ==================
void saveToFile()
{
    ofstream out("students_data.txt");
    for (auto &s : students)
        out << s.id << "," << s.name << "," << s.marks << "\n";
}

void loadFromFile()
{
    ifstream in("students_data.txt");
    students.clear();
    string line;
    while(getline(in, line))
    {
        stringstream ss(line);
        string token;
        Student s;
        getline(ss, token, ',');
        s.id = stoi(token);
        getline(ss, s.name, ',');
        getline(ss, token, ',');
        s.marks = stod(token);
        students.push_back(s);
    }
    // update nextId
    int maxId = 0;
    for(auto &s: students)
        if(s.id > maxId) maxId = s.id;
    nextId = maxId + 1;
}
