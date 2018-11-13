/*file_sort:
 * Sorts files of a given structure
 * Sorts ascending lexicographically
 */
#ifndef FILE_SORT_H
#define FILE_SORT_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class file_sort
{
public:
    file_sort(string dir="rfiles");

private:
    string __dir;
    vector<string> file_names;
};

#endif // FILE_SORT_H
