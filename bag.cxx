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
        std::cout << "assign" << std::endl;
        memcpy(this->data, rhs.data, DATASIZE);
        return *this;
    }

    // move constructor
    Bag::Bag(Bag &&rhs) {
        std::cout << "move constructor; calling assignment" << std::endl;
        this->operator=(rhs);
    }    

    // copy constructor
    Bag::Bag(const Bag &rhs) {
        std::cout << "copy; calling assignment" << std::endl;
        this->operator=(rhs);
    }    

    // move
    Bag &Bag::operator=(Bag &&rhs) {
        std::cout << "move; calling assign" << std::endl;
        return this->operator=(rhs);
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
    void Bag::enQ(const Data &) {};
    Bag::Data Bag::deQ() {
        if (count == 0)
            throw std::out_of_range(std::string("queue underflow"));
        Data value = data[head];
        head = (head + 1) % DATASIZE;
        count -= 1;
        return value;
    };    void Bag::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[(head + i) % DATASIZE] << " ";
        }
        std::cout << std::endl;
    };
}