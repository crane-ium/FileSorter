#include "file_sort.h"

file_sort::file_sort(const string& fname, const string& dir)
    : __dir(dir), __fname(fname)
{
    __dir = "../" + __dir;
}

void file_sort::run(){
    //opens streams of all the files, then starts sorting
    int count = 0;
    bool exists_flag = true;
    while(exists_flag){
        ifstream* fptr = new ifstream();
        fptr->open(__dir+"/"+__fname+to_string(count)+".txt", fstream::in);
        if(fptr->is_open()){
            __f_vec.push_back(fptr);
            string str;
            (*fptr) >> str;
            __next.push_back(str);
            cout << str << endl;
            count++;
        }else{
            exists_flag = false;
        }
    }
    cout << __dir << " " << __fname << endl;
    cout << "Opened " << count << " files\n";

    //Start sorting files
    ofstream sortedfile;
    sortedfile.open("../"+__fname+".txt", fstream::out | fstream::trunc);
    string* smallest;
    size_t i, c;
    LARGE_INTEGER frequency, start_t, end_t;
    double total_t;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_t);

    if(sortedfile.is_open()){
        //Major work in here
        cout << "Starting\n";
        while(__f_vec.size() > 0){
            smallest = &__next[0];
            i = 0;
            for(c = 1; c < __f_vec.size(); c++){
                if(__next[c].size() < (*smallest).size()
                    || (__next[c].size() == (*smallest).size()
                        && __next[c] < (*smallest))){
                    smallest = &__next[c];
                    i = c;
                }
            }
            sortedfile << (*smallest) << " ";
//            cout << (*smallest) << " ";
            if(!((*__f_vec[i]) >> __next[i])){
                auto it = __f_vec.begin() + i;
                (*it) = move(__f_vec.back());
                __f_vec.pop_back();
                auto nit = __next.begin() + i;
                (*nit) = move(__next.back());
                __next.pop_back();
            }
        }
    }else
        cout << __fname << " not open\n";
    QueryPerformanceCounter(&end_t);
    total_t = (end_t.QuadPart - start_t.QuadPart) * 1000.0 / frequency.QuadPart;
    //close all
    cout << "Time was " << total_t << " milliseconds\n";
    sortedfile.close();
    for(size_t i = 0; i < __f_vec.size(); i++){
        __f_vec[i]->close();
    }
}

void file_sort::sort_file(const string &fname){
//    return; //dont' let this run atm
    //fname: Don't include .txt in the parameter
    //Sorts a specific file in-place
    ifstream infile;
    ofstream outfile;
//    const char* inf = (__dir+"/"+fname+".txt\0");
    bool check = rename(string(__dir+"/"+fname+".txt\0").c_str()
           , string(__dir+"/tempsort.txt").c_str());
    if(check)
        cout << "Could not rename\n";
    infile.open(__dir+"/tempsort.txt");
    outfile.open(__dir+"/"+fname+".txt");
    if(infile.is_open() && outfile.is_open()){


        infile.close();
        outfile.close();
        remove(string(__dir+"/tempsort.txt").c_str());
    }else{
        cout << "Error opening\n";
        return;
    }
}
