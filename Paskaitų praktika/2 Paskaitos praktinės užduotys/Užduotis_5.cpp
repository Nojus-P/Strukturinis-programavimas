#include <iostream>

using namespace std;

int main() {
    double x1, x2, x3, x4, x5;

    cout << "Iveskite 5 skaicius";

    cin >> x1 >> x2 >> x3 >> x4 >> x5;

    double vidurkis = (x1 + x2 + x3 + x4 + x5) / 5.0;
    cout << "Vidurkis " << vidurkis << endl;

    return 0;
}
