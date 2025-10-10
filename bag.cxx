/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * recipe for containers using C-style array
 */
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string.h>
#include "bag.h"

namespace csen79 {

    // assignment
    Bag &Bag::operator=(const Bag &rhs) {
        memcpy(data, rhs.data, DATASIZE);
        first = rhs.first;
        count = rhs.count;
        return *this;
    }

    // move constructor
    Bag::Bag(Bag &&rhs) {
        operator=(rhs);
    }    

    // copy constructor
    Bag::Bag(const Bag &rhs) {
        operator=(rhs);
    }    

    // move
    Bag &Bag::operator=(Bag &&rhs) {
        return operator=(rhs);
    }


    //Add data to end of Q
    void Bag::enQ(const Data &element) {
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
    Bag::Data Bag::deQ() {
        if (count == 0)
            throw std::out_of_range(std::string("queue underflow"));
        Data value = data[first];
        first = (first+1)%DATASIZE;
        count--;
        return value;
    };
    //Prints the data to cout
    void Bag::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[(first + i) % DATASIZE] << " ";
        }
        std::cout << std::endl;
    };
}