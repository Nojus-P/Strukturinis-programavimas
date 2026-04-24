#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 50;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menuList[], int &count) {
    ifstream inFile("menu.txt");

    if (!inFile) {
        cout << "KLAIDA: menu.txt nerastas!\n";
        exit(1);
    }

    count = 0;

    while (inFile >> menuList[count].menuItem >> menuList[count].menuPrice) {
        count++;
    }

    inFile.close();
}

int getMaxLength(menuItemType menuList[], int count) {
    int maxLen = 0;

    for (int i = 0; i < count; i++) {
        if (menuList[i].menuItem.length() > maxLen) {
            maxLen = menuList[i].menuItem.length();
        }
    }

    return maxLen;
}

void showMenu(menuItemType menuList[], int count) {
    int maxLen = getMaxLength(menuList, count);

    cout << "\n=== PUSRYCIU MENIU ===\n\n";

    for (int i = 0; i < count; i++) {
        cout << setw(2) << i + 1 << ". "
             << setw(maxLen + 5) << left << menuList[i].menuItem
             << fixed << setprecision(2)
             << menuList[i].menuPrice << " EUR\n";
    }

    cout << "\nPasirinkite patiekalus.\n";
    cout << "0 - baigiau rinktis patiekalus\n\n";
}

void printCheck(menuItemType menuList[], int order[], int count) {
    ofstream outFile("receipt.txt");

    int maxLen = getMaxLength(menuList, count);

    double subtotal = 0;

    cout << "\n===== JUSU SASKAITA =====\n\n";
    outFile << "===== JUSU SASKAITA =====\n\n";

    for (int i = 0; i < count; i++) {
        if (order[i] > 0) {
            double sum = order[i] * menuList[i].menuPrice;
            subtotal += sum;

            cout << setw(2) << order[i] << " "
                 << setw(maxLen + 5) << left << menuList[i].menuItem
                 << fixed << setprecision(2)
                 << sum << " EUR\n";

            outFile << setw(2) << order[i] << " "
                    << setw(maxLen + 5) << left << menuList[i].menuItem
                    << fixed << setprecision(2)
                    << sum << " EUR\n";
        }
    }

    double tax = subtotal * 0.21;
    double total = subtotal + tax;

    cout << "\nPVM (21%): " << fixed << setprecision(2) << tax << " EUR\n";
    cout << "Galutine suma: " << total << " EUR\n";

    outFile << "\nPVM (21%): " << tax << " EUR\n";
    outFile << "Galutine suma: " << total << " EUR\n";

    outFile.close();
}

int main() {
    menuItemType menuList[SIZE];
    int order[SIZE] = {0};
    int count;

    getData(menuList, count);

    cout << "Sveiki atvyke i restorana!\n";

    showMenu(menuList, count);

    int choice, quantity;

    while (true) {
        cout << "Pasirinkimas: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaida: iveskite skaiciu!\n";
            continue;
        }

        if (choice == 0) {
            cout << "\nBaigete rinktis patiekalus.\n";
            break;
        }

        if (choice < 1 || choice > count) {
            cout << "Tokio patiekalo nera!\n";
            continue;
        }

        cout << "Kiek porciju?: ";

        if (!(cin >> quantity) || quantity <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaida: blogas kiekis!\n";
            continue;
        }

        order[choice - 1] += quantity;
    }

    printCheck(menuList, order, count);

    cout << "\nAciu, kad apsilankete Nojaus kavineje!\n";

    return 0;
}