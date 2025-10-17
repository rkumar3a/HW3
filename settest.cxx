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
#include "set.h"

using namespace std;
using namespace csen79;
enum Command { INSERT = 'I', SIZE = 'S', PRINT = 'P', QUIT = 'Q' };

int main(void) {
    Set set; // The Set object
    string line;
    bool quit = false;
    // Data type should match what Set::insert() expects (likely int, based on your Set implementation)
    int data; 

    while (!quit && std::getline(cin, line)) {
        // Ensure the line is not empty before checking the first character
        if (line.empty()) continue; 

        switch (line[0]) {
        case INSERT:
            try {
                //Correctly parse the data from the rest of the line
                stringstream ss(line.substr(1)); 
                if (!(ss >> data)) {
                    // Check if stream extraction failed (e.g., no number after 'I')
                    cerr << "Error: No data provided for INSERT command." << endl;
                    continue;
                }
            } catch (const out_of_range &e) {
                // The substring and stringstream operations typically don't throw out_of_range here.
                cerr << "Data Parsing Error." << endl;
                continue;
            }

            try {
                //Call the insert method on the 'set' object
                set.insert(data);
            } catch (const exception &e) {
                // Use a general exception catch for errors during insert (like out of memory)
                cerr << e.what() << endl;
                continue;
            }
            break;

        case SIZE:
            try {
                //Call the size method on the 'set' object
                cout << "Current Size: " << set.size() << endl; 
            } catch (const exception &e) {
                 //The size function shouldn't throw, but keep the try-catch for robustness
                std::cerr << "Caught exception: " << e.what() << std::endl;
                throw std::runtime_error("Error getting size.");
            }
            break;

        case PRINT:
            cout << "Printing Set:" << endl;
            set.print();
            break;

        case QUIT:
            quit = true;
            break;

        default:
            cerr << "Unknown Command: " << line << endl;
            break;
        }
    }
    
    return EXIT_SUCCESS;
}