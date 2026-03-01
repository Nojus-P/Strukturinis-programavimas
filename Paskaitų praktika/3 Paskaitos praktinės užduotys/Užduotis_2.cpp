#include<iostream>

using namespace std;

int main() {

    int x1, x2, x3, x4, x5;

    cout << "Irasykite studento pazymius ";

    cin>>x1>>x2>>x3>>x4>>x5;

    int vidurkis = (x1 + x2 + x3 + x4 + x5) / 5;

    if (vidurkis >= 5) {
        cout << "Vidurkis teigiamas" << endl;
    }

    if (vidurkis <= 4) {
        cout << "Vidurkis neigiamas" << endl;
    }

    return 0;
}