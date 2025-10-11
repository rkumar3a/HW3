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
#include "stack.h"

namespace csen79 {

    // assignment
    Stack &Stack::operator=(const Stack &rhs) {
        memcpy(data, rhs.data, DATASIZE);
        first = rhs.first;
        count = rhs.count;
        return *this;
    }

    // move constructor
    Stack::Stack(Stack &&rhs) {
        operator=(rhs);
    }    

    // copy constructor
    Stack::Stack(const Stack &rhs) {
        operator=(rhs);
    }    

    // move
    Stack &Stack::operator=(Stack &&rhs) {
        return operator=(rhs);
    }


    //Add data to end of Q
    void Stack::enQ(const Data &element) {
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
    Stack::Data Stack::deQ() {
        if (count == 0)
            throw std::out_of_range(std::string("queue underflow"));
        Data value = data[first];
        first = (first+1)%DATASIZE;
        count--;
        return value;
    };
    //Prints the data to cout
    void Stack::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[(first + i) % DATASIZE] << " ";
        }
        std::cout << std::endl;
    };
}