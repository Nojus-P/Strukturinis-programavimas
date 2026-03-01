#include <iostream>
using namespace std;

int main() {

    int suma = 0;

    for (int i = 1; i <= 20; i++) {

        if (i % 2 != 0) {
            suma += i;
        }
    }

    cout << "Nelyginiu skaiciu suma: " << suma << endl;

    return 0;
}