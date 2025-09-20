
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include "Student.h"

void displayStudent(const Student &s)
{
    std::cout << "ID: " << s.id
              << ", Name: " << s.name
              << ", Marks: " << s.marks
              << ", Age: " << s.age << "\n";
}

void displayAllStudents(const std::vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "No students found.\n";
        return;
    }
    for (const auto &s : students) displayStudent(s);
}

#endif
