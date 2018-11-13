/*file_sort:
 * Sorts files of a given structure
 * Sorts ascending lexicographically
 */
#ifndef FILE_SORT_H
#define FILE_SORT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <string>

using namespace std;

class file_sort
{
public:
    file_sort(const string &fname="rfile", const string &dir="rfiles");

    void run();
    void sort_file(const string& fname);
    bool check_sorted() const;
private:
    string __dir;
    string __fname;
    vector<string> __next; //Stores corresponding string for that vec
    vector<ifstream*> __f_vec;
};

#endif // FILE_SORT_H
