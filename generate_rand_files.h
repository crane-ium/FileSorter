//Generates multiple random files
#ifndef GENERATE_RAND_FILES_H
#define GENERATE_RAND_FILES_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void generate_files(const size_t files=3,
                    const size_t length=100000,
                    const size_t min=1, const size_t max=10, const string& fnames="rfile",
                    const string &dir="rfiles");


string gen_istring(const long long min, const long long max);
string gen_string(const size_t min, const size_t max);

#endif // GENERATE_RAND_FILES_H
