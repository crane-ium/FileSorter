#include "fsort.h"

std::size_t STR_LEN = 1024;
std::string RFILENAME = "../rfiles/rfiles"; //with \d+.txt conc'd on
std::size_t BASECOUNT = 1024 * 1; //# of integer-str per file
std::size_t FILECOUNT = 100;
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
    std::cout << "Opening files\n";
    while(true){ //BRING IT ON INFINTE LOOP!
        std::ifstream* fptr = new std::ifstream();
        fptr->open(RFILENAME+std::to_string(count)+".txt", std::fstream::in);
        if(fptr->is_open()){
//            std::cout << "Opened " << RFILENAME << std::to_string(count) << std::endl;
            stream_vec.push_back(fptr);
            char* str = new char[STR_LEN+1];
//            (*fptr) >> (*str); //of len SIZE_LEN + 1;
            fptr->read(str, STR_LEN);
//            std::cout << "here\n";
//            std::cout << str << std::endl;
            cstr_vec.push_back(str);
//            cout << str << endl;
            count++;
        }else
            break;
    }
    std::cout << "Opened " << count << " files\n";

    std::ofstream sortedfile;
    //flag the file so a huge file is not accessed, and set for rewrite
    sortedfile.open(WFILENAME+".txt", std::fstream::out | std::fstream::trunc);
    char* smallest; //track the smallest
    size_t i, j, i_small;
    //Now that we have our streams open, let's play!
    if(sortedfile.is_open()){
        std::cout << "Starting fsort\n";
        while(true){//BRING IT ON TRUE WHILE! Let's avoid comparisons where possible
            smallest = cstr_vec[0];
            i_small = 0;
            for(i = 1; i < count; i++){
                for(j = 0; j < STR_LEN; j++){
                    //Compare chars until we determine the smaller
                    if(smallest[j] == cstr_vec[i][j])
                        continue;
                    if(smallest[j] > cstr_vec[i][j]){
                        smallest = cstr_vec[i];
                        i_small = i;
                        break;
                    }else
                        break;
                }
            }
            //knows smallest, now add that to file
            sortedfile << smallest << " ";
//            std::cout << smallest << std::endl;
//            std::cout << "Got here\n";
            if(!(stream_vec[i_small]->read(cstr_vec[i_small], STR_LEN))){
//            if(!((*stream_vec[i_small]) >> cstr_vec[i_small])){
                auto it = stream_vec.begin() + i_small;
                (*it)->close(); //CLOSE STREAM!
                delete (*it);
                (*it) = std::move(stream_vec.back());
                stream_vec.pop_back();
                auto nit = cstr_vec.begin() + i;
                delete[] (*nit);
                (*nit) = std::move(cstr_vec.back());
                cstr_vec.pop_back();
                count--;
//                std::cout << "Removed, at " << count << std::endl;
                if(!count)
                    break; //END TRUE WHILE LOOP
            }
        }
    }else
        std::cout << "Could not open " << WFILENAME << std::endl;
//    for(std::size_t i = 0; i < stream_vec.size(); i++){
//        delete stream_vec[0];
//        delete[] cstr_vec[0];
//    }
    sortedfile.close();
}
