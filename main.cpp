#include <iostream>
#include <ctime>

#include "generate_rand_files.h"
#include "file_sort.h"

using namespace std;

int main()
{
//    srand(time(NULL));
//    cout << gen_string(5, 10) << endl;
    generate_files(100, 10000);
    file_sort sorter;
    sorter.run();

    string one, two;

//    sorter.sort_file("rfile0");

    return 0;
}
