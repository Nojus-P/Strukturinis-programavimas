#include <iostream>

using namespace std;

int main() {

    double suma = 1000;
    double palukanos = 0.05;
    int metai = 10;

    for (int i = 1; i <= metai; i++) {
        suma = suma + suma * palukanos;
    }

    cout << "Suma po 10m = " << suma << "EUR" << endl;

    return 0;
}