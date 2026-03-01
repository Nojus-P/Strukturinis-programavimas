#include <iostream>
using namespace std;

int main() {

    int ivertinimai[40];
    int kiekiai[11] = {0};

    cout << "Iveskite 40 ivertinimu (1-10):" << endl;

    for (int i = 0; i < 40; i++) {
        cin >> ivertinimai[i];

        int balas = ivertinimai[i];
        kiekiai[balas]++;
    }

    cout << endl << "Rezultatai:" << endl;

    for (int balas = 1; balas <= 10; balas++) {
        cout << balas << " balu: " << kiekiai[balas] << " kartu" << endl;
    }

    return 0;
}