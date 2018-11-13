#include <iostream>
#include <ctime>

#include "generate_rand_files.h"
#include "file_sort.h"

using namespace std;

int main()
{
//    srand(time(NULL));
//    cout << gen_string(5, 10) << endl;
//    if(false)
        generate_files(100, 1000000);
    file_sort sorter;
    sorter.run();

    cout << "Sorted: " << (sorter.check_sorted()?"True":"False") << endl;

//    sorter.sort_file("rfile0");

    return 0;
}
