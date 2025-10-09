/*
 * Itay Volk <ivolk@scu.edu>,
 * David Chousal Cantu <dchousal@scu.edu>,
 * Ding-Shiuan Yang <dyang2@scu.edu>,
 * Rushil Kumar <rkumar3@scu.edu>,
 * Alexander Anokhin <aanokhin@scu.edu>
 * Test data generation program
 */

#include <iostream>

using namespace std;

int main(void) {
    for (int i = 1; i <= 100; i++) {
        cout << "P " << i << endl;
    }
    cout << "D" << endl;
    for (int i = 101; i <= 1001; i++) {
        cout << "P " << i << endl;
    }
    cout << "D" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "O" << endl;
    }
    cout << "D" << endl;
    for (int i = 1002; i <= 1021; i++) {
        cout << "P " << i << endl;
    }
    cout << "D" << endl;
    for (int i = 0; i < 1001; i++) {
        cout << "O" << endl;
    }
    cout << "D" << endl;
    for (int i = 1022; i <= 1041; i++) {
        cout << "P " << i << endl;
    }
    cout << "D" << endl << "Q" << endl;
}