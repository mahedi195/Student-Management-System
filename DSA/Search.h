#ifndef SEARCH_H
#define SEARCH_H
#include <vector>
#include "../student.h"
using namespace std;

inline int linearSearchByName(vector<Student>& v, string name)
{
    for(int i=0; i<v.size(); i++) if(v[i].name == name) return i;
    return -1;
}

inline int binarySearchByMarks(vector<Student>& v, int marks)
{
    int left=0, right=v.size()-1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(v[mid].marks == marks) return mid;
        else if(v[mid].marks < marks) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

#endif
