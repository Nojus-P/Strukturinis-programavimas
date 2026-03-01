#include<iostream>

using namespace std;

int main() {

    int pazimys;

    cout << "Iveskite pazimi";
    cin >> pazimys;

    if (pazimys == 10) {
        cout << "Puikiai" << endl;
    }

    else if (pazimys >= 9) {
        cout << "Labai gerai" << endl;
    }

    else if (pazimys >=7) {
        cout << "Gerai" << endl;
    }

    else if (pazimys >= 5) {
        cout << "Patenkinamai" << endl;
    }

    else if (pazimys <= 4) {
        cout << "Egzaminas neislaikytas" << endl;
    }
    return 0;
}