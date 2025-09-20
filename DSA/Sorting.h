#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include "../student.h"
using namespace std;

inline void insertionSortByName(vector<Student>& v)
{
    int n = v.size();
    for(int i=1; i<n; i++)
    {
        Student key = v[i];
        int j=i-1;
        while(j>=0 && v[j].name > key.name)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

inline void insertionSortByMarks(vector<Student>& v)
{
    int n = v.size();
    for(int i=1; i<n; i++)
    {
        Student key = v[i];
        int j=i-1;
        while(j>=0 && v[j].marks > key.marks)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

#endif
