/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * recipe for containers using pointers
 */
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string.h>
#include "set.h"

namespace csen79 {

    // assignment
    Set &Set::operator=(const Set &rhs) {
        memcpy(data, rhs.data, DATASIZE);
        first = rhs.first;
        count = rhs.count;
        return *this;
    }

    // move constructor
    Set::Set(Set &&rhs) {
        operator=(rhs);
    }    

    // copy constructor
    Set::Set(const Set &rhs) {
        operator=(rhs);
    }    

    // move
    Set &Set::operator=(Set &&rhs) {
        return operator=(rhs);
    }


    //Add data to end of Q
    void Set::enQ(const Data &element) {
        //Check if adding doesn't surpass limits
        if (count >= DATASIZE){
            throw std::out_of_range("The Queue is Full. DeQ Items to Add More.");
        }

        //Set data at the end
        data[(first+count)%DATASIZE] = element;

        //Increment the count for every add
        count++;
    };
    //Remove data from end of Q
    Set::Data Set::deQ() {
        if (count == 0)
            throw std::out_of_range(std::string("queue underflow"));
        Data value = data[first];
        first = (first+1)%DATASIZE;
        count--;
        return value;
    };
    //Prints the data to cout
    void Set::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[(first + i) % DATASIZE] << " ";
        }
        std::cout << std::endl;
    };
}