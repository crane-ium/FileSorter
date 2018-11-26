#include "fsort.h"

std::size_t STR_LEN = 1024;
std::string RFILENAME = "../rfiles/rfiles"; //with \d+.txt conc'd on
std::size_t BASECOUNT = 1024 * 100; //# of integer-str per file
std::size_t FILECOUNT = 10;
std::string WFILENAME = "../sfile.txt";


//size of file is STR_LEN * count (bytes)
void gen_file(//std::size_t length,
//              std::size_t count,
//              const std::string &filename
              )
{

//    std::size_t count = BASECOUNT;
    for(std::size_t i = 0; i < FILECOUNT; i++){
        std::string fname = RFILENAME+std::to_string(i)+".txt";
        std::ofstream file;
        istr intstr;

        file.open(fname);
        if(file.is_open()){
            //While we increase our obj intstr, we will add the c_strs
            //into the buffer!
            for(std::size_t j = 0; j < BASECOUNT;j++){
                intstr.inc();
                file << (char*)intstr << " ";
            }
        }else{
            std::cout << "No file: " << fname << std::endl;
            continue;
        }
        std::cout << "Made " << fname << std::endl;
        file.close();
    }
}


//sort the files
void sort_files(){
    //We will need to open up all those file streams!
    //Variable definitions
    std::vector<char*> cstr_vec;
    std::vector<std::ifstream*> stream_vec;
    std::size_t count = 0;
    while(true){ //BRING IT ON INFINTE LOOP!
        std::ifstream* fptr = new std::ifstream();
        fptr->open(RFILENAME+std::to_string(count)+".txt", std::fstream::in);
        if(fptr->is_open()){
            stream_vec.push_back(fptr);
            char* str;
            (*fptr) >> (*str); //of len SIZE_LEN + 1;
            cstr_vec.push_back(str);
//            cout << str << endl;
            count++;
        }else
            break;
    }
    std::cout << "Opened " << count << " files\n";


}
