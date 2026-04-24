#include <iostream>
using namespace std;

int main() {
    int mas[5];
    int suma = 0;

    for(int i = 0; i < 5; i++) {
        cout << "Iveskite skaiciu: ";
        cin >> mas[i];
    }

    int max = mas[0];
    int min = mas[0];

    for(int i = 0; i < 5; i++) {
        suma += mas[i];

        if(mas[i] > max) {
            max = mas[i];
        }

        if(mas[i] < min) {
            min = mas[i];
        }
    }

    cout << "Suma: " << suma << endl;
    cout << "Didziausias: " << max << endl;
    cout << "Maziausias: " << min << endl;

    return 0;
}