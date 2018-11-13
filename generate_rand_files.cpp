#include "generate_rand_files.h"
#include <random>

/**
 * @brief generate_files
 * @param files: file count
 * @param fnames:basefile name
 * @param min: minimum string length
 * @param max: max string length
 * @param length: count of strings per file
 * @param dir: directory
 */
void generate_files(const size_t files,
                    const size_t length, const string& fnames,
                    const size_t min, const size_t max,const string& dir){
    for(size_t i = 0; i < files; i++){
        //create multiple files
        string fname = fnames+to_string(i)+".txt";
        ofstream file;
        file.open(("../"+dir+"/"+fname));
        if(file.is_open())
            for(size_t j = 0; j < length; j++){
                file << gen_string(min, max) << " ";
            }
        else{
            cout << "No file: " << fname << endl;
            continue;
        }
        file.close();
    }
}

string gen_string(const size_t min, const size_t max){
    string gstring = "";
    size_t str_size = rand() % (max-min) + min;

    for(size_t i = 0; i < str_size; i++){
//        if(rand()%2)
//            gstring += char(int('a')+(rand()%26));
//        else
//            gstring += char(int('A')+(rand()%26));
        gstring += char(int('0')+rand()%10);
    }

    return gstring;
}
