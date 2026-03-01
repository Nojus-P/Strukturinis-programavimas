#include <iostream>
using namespace std;

int main() {

    int skaicius;

    cout << "Ivesk dvizenkli skaiciu: ";
    cin >> skaicius;

    int desimtys = skaicius / 10;
    int vienetai = skaicius % 10;

    int suma = desimtys + vienetai;

    cout << "Skaitmenu suma: " << suma << endl;

    return 0;
}