/*
 * Sin-Yaw Wang <swang24@scu.edu>
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


    // simple asssess functions
    // replace them with appropriate ones for assignments
    const Bag::Data &Bag::getData(const int i) const {
        if (i < 0 || i >= DATASIZE)
            throw std::out_of_range(std::string("index out of range"));
        return data[i];
    };
    void Bag::setData(const int i, const Data &d) {
        if (i < 0 || i >= DATASIZE)
            throw std::out_of_range(std::string("index out of range"));
        data[i] = (Data) d;
    }
    void Bag::enQ(const Data &element) {
        //Check if adding doesn't surpass limits
        if (count >= DATASIZE){
            throw std::out_of_range("The Queue is Full. DeQ Items to Add More.");
        }

        //Set data at the end
        setData((first+count)%DATASIZE, element);

        //Increment the count for every add
        count++;
    };
    Bag::Data Bag::deQ() {
        if (count == 0)
            throw std::out_of_range(std::string("queue underflow"));
        Data value = data[first];
        first = (first + 1) % DATASIZE;
        count -= 1;
        return value;
    };
    void Bag::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[(first + i) % DATASIZE] << " ";
        }
        std::cout << std::endl;
    };
}