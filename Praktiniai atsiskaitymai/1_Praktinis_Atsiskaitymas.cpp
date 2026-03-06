#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double GBP_Bendras = 0.8729;
    double GBP_Pirkti = 0.8600;
    double GBP_Parduoti = 0.9220;

    double USD_Bendras = 1.1793;
    double USD_Pirkti = 1.1460;
    double USD_Parduoti = 1.2340;

    double INR_Bendras = 104.6918;
    double INR_Pirkti = 101.3862;
    double INR_Parduoti = 107.8546;

    int pasirinkimas;
    int valiuta;
    double kiekis;
    double rezultatas;

    cout << "1 - Palyginti kursa" << endl;
    cout << "2 - Pirkti valiuta" << endl;
    cout << "3 - Parduoti valiuta" << endl;
    cin >> pasirinkimas;

    cout << "Pasirink valiuta: 1-GBP 2-USD 3-INR" << endl;
    cin >> valiuta;

    if (pasirinkimas == 1) {

        if (valiuta == 1) cout << "GBP kursas: " << GBP_Bendras << endl;
        if (valiuta == 2) cout << "USD kursas: " << USD_Bendras << endl;
        if (valiuta == 3) cout << "INR kursas: " << INR_Bendras << endl;

    }
    else if (pasirinkimas == 2) {

        cout << "Iveskite EUR suma: ";
        cin >> kiekis;

        if (valiuta == 1) rezultatas = kiekis * GBP_Pirkti;
        if (valiuta == 2) rezultatas = kiekis * USD_Pirkti;
        if (valiuta == 3) rezultatas = kiekis * INR_Pirkti;

        cout << fixed << setprecision(2);
        cout << "Gausite: " << rezultatas << endl;
    }
    else if (pasirinkimas == 3) {

        cout << "Iveskite valiutos suma: ";
        cin >> kiekis;

        if (valiuta == 1) rezultatas = kiekis * GBP_Parduoti;
        if (valiuta == 2) rezultatas = kiekis * USD_Parduoti;
        if (valiuta == 3) rezultatas = kiekis * INR_Parduoti;

        cout << fixed << setprecision(2);
        cout << "Gausite: " << rezultatas << " EUR" << endl;
    }

    return 0;
}