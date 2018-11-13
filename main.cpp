#include <iostream>
#include <ctime>
#include "generate_rand_files.h"


using namespace std;

int main()
{
    srand(time(NULL));
    cout << gen_string(5, 10) << endl;
    generate_files(10, 1000000);

    return 0;
}
