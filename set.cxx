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


    //Add data to set if not inside
    void Set::insert(const Data &element) {
        //Check if data isn't in set
        for (int i = 0; i < count; i++) {
            if (data[i] == element) {
                return;
            }
        }

        //Increase size if necessary
        if (count == DATASIZE) {
            DATASIZE += 200;
            if (data != nullptr) {
                Data* temp = new Data[DATASIZE];
                memcpy(temp, data, count*sizeof(Data));
                delete data;
                data = temp;
            } else {
                data = new Data[DATASIZE];
            }
        }

        data[count++] = element; //Insert data and increment
    };
    //Return the number of elements in the set
    int Set::size() {return 0;};
    //Prints the data to cout
    void Set::print() const {
        for (int i = 0; i < count; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    };
}