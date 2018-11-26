#include <iostream>
#include <ctime>
#include <windows.h>
#include <functional>

#include "generate_rand_files.h"
#include "file_sort.h"
#include "file_gen.h"

using namespace std;

int main()
{
    istr i;
    i += 999;
    i += 1;
    char* c = i;
    srand(time(NULL));
    for(int x = 0; x < 1024; x++)
        i.inc();
    for(int i=0; i < 1024; i++)
        cout << c[i];
    cout << endl;

//recursive lambda tests
//    std::function<void(char*)> carry = [&carry](char* cptr){
//        if(*cptr > '9'){
//            *cptr -= 10;
//            *(cptr-1) += 1;
//            carry(cptr-1);
//        }
//    };
//    char istr[10];
//    for(int i =0; i<10;i++)
//        istr[i] = '0';
//    istr[9] += 11;
//    istr[8] += 9;
//    istr[7] += 9;
//    carry(&istr[9]);
//    for(int i =0; i < 10; i++)
//        cout << istr[i];
//    cout << endl;


//    srand(time(NULL));
//    cout << gen_string(5, 10) << endl;
//    if(false)
//        generate_files(100, 10000);
//    file_sort sorter;
//    sorter.run();

//    cout << "Sorted: " << (sorter.check_sorted()?"True":"False") << endl;

//    sorter.sort_file("rfile0");

    return 0;
}
