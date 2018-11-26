/**
  @{
    Purpose: Generate a static length integer-string sorted file

    @author NehpetS Crane
  }@
  */
#ifndef FILE_GEN_H
#define FILE_GEN_H

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <math.h>
#include <functional>
#include <cassert>
#include <vector>


extern std::size_t STR_LEN;
extern std::string RFILENAME;
extern std::size_t BASECOUNT;
extern std::size_t FILECOUNT;
extern std::string WFILENAME;

/**
 * @brief gen_file : Generates a sorted file
 * @param length : Length of each integer-string
 * @param count : number of integer-strings per file
 */
void gen_file(//std::size_t length=STR_LEN,
//              const std::size_t count,
//              const std::string& filename=RFILENAME
        );

//This does all the hardwork to sort!
void sort_files();

//returns a rand larger than 32767
long long rand_huge(const long long bound);

//THE ULTIMATE ENCAPSULATION OF A CHAR ARRAY REPRESENTATION OF INFINITE INTEGERS!!! MUAHAHAHA
//-supports: addition with +=
//-nice!
struct istr{
    //encapsulation of an intstr array
    istr():intstr(new char[STR_LEN+1]){
        for(std::size_t i = 0; i < STR_LEN; i++)
            intstr[i] = '0';
        intstr[STR_LEN] = '\0'; //set null term
    }
    ~istr(){delete[] intstr;}
    operator char*() const{
        return intstr;
    }
    //THESE 2 FUNCTIONS DOWN BELOW HERE, THEY'RE PRETTY BADASS
    void inc(){
        //Increase the int-str by a random amount where the max
        //It can increase is less than 10^STR_LEN/BASECOUNT
        //AKA the leftmost index to increase is...
        std::size_t i_left = ceil(log10(BASECOUNT)) - 1;
        std::size_t left_max = (std::size_t(pow(10, i_left+1))/BASECOUNT);
//        std::cout << "ileft/leftmax: " << i_left << "/" << left_max << std::endl;
        //now we know which index is the leftmost, and how much
        //we can possibly increase it by!
        //Using rand, we will increment each cell
        for(std::size_t i = i_left; i < STR_LEN; i++){
            if(i == i_left){
                //special case: i_left max
                intstr[i] += rand() % (left_max+1);
                continue;
            }
            intstr[i] += rand() % 10;
        }
        //Now carry over all 1s
        for(std::size_t i = 0; i < STR_LEN-1;i++){
            if(intstr[STR_LEN - i - 1] > '9'){
                intstr[STR_LEN - i - 1] -= 10;
                intstr[STR_LEN - i - 2] += 1;
            }
        }
        if(intstr[0] > '9'){
            assert(true);
        }
    }
    void operator +=(const std::size_t rhs){
        //Increment each corresponding index
        int count = 1;
        std::size_t adder = rhs; //I think this is more efficient than other options
        while(adder > 0){ //Keep incrementing each digit from the least sig dig
            std::size_t next_digit = adder % (std::size_t)pow(10, count);
            adder -= next_digit;
            next_digit /= pow(10, count-1);
//            std::cout << adder << " " << next_digit << std::endl;
            intstr[STR_LEN-count] += next_digit;
            //Create recursive functions to carry 1 over digits
            std::function<void(char*)> carry = [this, &carry](char* cptr){
                if(*cptr > '9'){
                    *cptr -= 10;
                    if(cptr == intstr)
                        return;
                    *(cptr-1) += 1;
                    carry(cptr-1);
                }
            };
            carry(&intstr[STR_LEN-count]);
            count++;
        }
    }
    char* intstr;
};

#endif // FILE_GEN_H
