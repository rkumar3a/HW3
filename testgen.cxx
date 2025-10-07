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
    for (int i = 0; i < 981; i++) {
        cout << "O" << endl;
    }
    cout << "D" << endl;
    for (int i = 1022; i <= 1041; i++) {
        cout << "P " << i << endl;
    }
    cout << "D" << endl << "Q" << endl;
}