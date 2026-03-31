#include <iostream>
#include <string>

using namespace std;

int main() {

    string vardai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];
    int mokiniuKiekis = 0;

    while (true) {
        cout << "\n1 - Prideti mokini" << endl;
        cout << "2 - Perziureti visus" << endl;
        cout << "3 - Atnaujinti pazymi" << endl;
        cout << "4 - Pasalinti mokini" << endl;
        cout << "0 - Iseiti" << endl;

        int pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == 0) {
            break;
        }

        if (pasirinkimas == 1) {

            if (mokiniuKiekis >= 100) {
                cout << "Negalima prideti daugiau mokiniu!" << endl;
                continue;
            }

            cout << "Iveskite varda: ";
            cin >> vardai[mokiniuKiekis];

            cout << "Kiek pazymiu?: ";
            cin >> pazymiuKiekis[mokiniuKiekis];

            if (pazymiuKiekis[mokiniuKiekis] < 0 || pazymiuKiekis[mokiniuKiekis] > 10) {
                cout << "Netinkamas pazymiu kiekis (0-10)!" << endl;
                continue;
            }

            for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++) {
                cout << "Iveskite pazymi: ";
                cin >> pazymiai[mokiniuKiekis][i];

                if (pazymiai[mokiniuKiekis][i] < 1 || pazymiai[mokiniuKiekis][i] > 10) {
                    cout << "Pazymys turi buti nuo 1 iki 10!" << endl;
                    i--; // leidžia įvesti dar kartą
                }            }

            mokiniuKiekis++;
        }

        if (pasirinkimas == 2) {

            if (mokiniuKiekis == 0) {
                cout << "Nera mokiniu!" << endl;
                continue;
            }

            for (int i = 0; i < mokiniuKiekis; i++) {

                cout << vardai[i] << ": ";

                for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }

                cout << endl;
            }
        }

        if (pasirinkimas == 3) {

            if (mokiniuKiekis == 0) {
                cout << "Nera mokiniu!" << endl;
                continue;
            }

            string vardas;
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;

            int indeksas = -1;

            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    indeksas = i;
                    break;
                }
            }

            if (indeksas == -1) {
                cout << "Mokinys nerastas!" << endl;
            } else {

                for (int j = 0; j < pazymiuKiekis[indeksas]; j++) {
                    cout << j + 1 << ": " << pazymiai[indeksas][j] << endl;
                }

                int nr;
                cout << "Kuri pazymi keisti?: ";
                cin >> nr;

                nr--;

                if (nr >= 0 && nr < pazymiuKiekis[indeksas]) {
                    int naujas;

                    do {
                        cout << "Naujas pazymys (1-10): ";
                        cin >> naujas;
                    } while (naujas < 1 || naujas > 10);

                    pazymiai[indeksas][nr] = naujas;
                } else {
                    cout << "Neteisingas numeris!" << endl;
                }
            }
        }

        if (pasirinkimas == 4) {

            if (mokiniuKiekis == 0) {
                cout << "Nera mokiniu!" << endl;
                continue;
            }

            string vardas;
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;

            int indeksas = -1;

            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    indeksas = i;
                    break;
                }
            }

            if (indeksas == -1) {
                cout << "Mokinys nerastas!" << endl;
            } else {

                for (int i = indeksas; i < mokiniuKiekis - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuKiekis[i] = pazymiuKiekis[i + 1];

                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }

                mokiniuKiekis--;

                cout << "Mokinys pasalintas!" << endl;
            }
        }
    }
}