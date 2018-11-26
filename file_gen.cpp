#include "file_gen.h"

std::size_t STR_LEN = 1024;
std::string RFILENAME = "../rfiles/rfiles"; //with \d+.txt conc'd on
std::size_t BASECOUNT = 1024 * 1;
std::size_t FILECOUNT = 10;


//size of file is STR_LEN * count (bytes)
void gen_file(//std::size_t length,
//              std::size_t count,
              const std::string &filename)
{

//    std::size_t count = BASECOUNT;
    for(std::size_t i = 0; i < FILECOUNT; i++){
        std::string fname = filename+std::to_string(i)+".txt";
        std::ofstream file;
        istr intstr;

        file.open(fname);
        if(file.is_open()){

        }else{
            std::cout << "No file: " << fname << std::endl;
            continue;
        }
        std::cout << "Made " << fname << std::endl;
        file.close();
    }
}
