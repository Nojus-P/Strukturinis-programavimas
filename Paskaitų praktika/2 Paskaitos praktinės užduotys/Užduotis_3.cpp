#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string marke = "Opel";
    string modelis = "Zafira";
    int metai = 1990;
    double litrazas = 1.9;
    string spalva = "zalios";

    cout << "Automobilis " << marke << " " << modelis << " yra pagamintas " << metai << " " << "metais. Jo motoras " << litrazas << " " << "litrazo." << " Automobilis yra " << spalva << " " << "spalvos." << endl;

    return 0;
}