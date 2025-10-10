/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * Test program
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include "bag.h"

using namespace std;
using namespace csen79;
enum Command { PUSH = 'P', POP = 'O', PRINT = 'D', QUIT = 'Q' };

int main(void) {
    Bag bag;
    string line;
    bool quit = false;
    int data;
    while (!quit && std::getline(cin,line)) {
        switch (line[0]) {
        case PUSH:
            try {
                stringstream ss(line.substr(1));
                ss >> data;
            } catch (const out_of_range &e) {
                cerr << "Data out of range" << endl;
                continue;
            }
            try {
                bag.enQ(data);
                cout << "Enqueued data: " << data << endl;
            } catch (const out_of_range &e) {
                cerr << e.what() << endl;
                continue;
            }
            break;
        case POP:
            try {
                data = bag.deQ();
                cout << "Dequeued data: " << data << endl;
            } catch (const out_of_range &e) {
                cerr << e.what() << endl;
                continue;
            }
            break;
        case PRINT:
            cout << "Printing bag:" << endl;
            bag.print();
            break;
        case QUIT:
            quit = true;
            break;
        default:
            cerr << "Unknown command: " << line << endl;
            break;
        }
    }
    
    return EXIT_SUCCESS;
}
