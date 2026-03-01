#include <iostream>

using namespace std;

int main() {
    int skaiciai [5];

    cout << "Iveskite 5 skaicius";
    for (int i = 0; i < 5; i++) {
        cin >> skaiciai[i];
    }
    int suma = 0;
    int didziausias = skaiciai[0];
    int maziausias = skaiciai[0];

    for (int i = 1; i < 5; i++) {
        suma += skaiciai[i];

        if (skaiciai[i] > didziausias) {
            didziausias = skaiciai[i];
        }
        if (skaiciai[i] < maziausias) {
            maziausias = skaiciai[i];
        }
    }
    cout << "Suma = " << suma << endl;
    cout << "Didziausias = " << didziausias << endl;
    cout << "Maziausias= " << maziausias << endl;

    return 0;
}