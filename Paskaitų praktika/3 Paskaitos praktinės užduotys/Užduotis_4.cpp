#include<iostream>

using namespace std;

int main() {
    int pazimys;

    cout << "Iveskite pazimi";
    cin >> pazimys;

    switch (pazimys) {
        case 10:
            cout << "Puiku";
            break;

        case 9:
            cout << "Labai gerai";
            break;

        case 8:
        case 7:
            cout << "Gerai";
            break;

        case 6:
        case 5:
            cout << "Patenkinamai";
            break;

        default:
            cout << "Egzaminas neislaikytas" << endl;
    }
    return 0;
}