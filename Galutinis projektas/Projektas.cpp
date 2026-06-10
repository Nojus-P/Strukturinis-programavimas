#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Component
{
    int id;
    string manufacturer;
    string model;
    string type;
    int price;
};
vector<Component> components;

void loadFromFile()
{
    ifstream file("components.txt");

    if (!file)
    {
        cout << "Nepavyko atidaryti failo!" << endl;
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        Component component;
        string temp;

        getline(ss, temp, ';');
        component.id = stoi(temp);

        getline(ss, component.manufacturer, ';');
        getline(ss, component.model, ';');
        getline(ss, component.type, ';');

        getline(ss, temp);
        component.price = stoi(temp);

        components.push_back(component);
    }

    file.close();
}

void showAllComponents()
{
    if (components.empty())
    {
        cout << "Komponentu sarasas tuscias." << endl;
        return;
    }

    for (int i = 0; i < components.size(); i++)
    {
        cout << "ID: " << components[i].id << endl;
        cout << "Gamintojas: " << components[i].manufacturer << endl;
        cout << "Modelis: " << components[i].model << endl;
        cout << "Tipas: " << components[i].type << endl;
        cout << "Kaina: " << components[i].price << " EUR" << endl;
        cout << "------------------------" << endl;
    }
}
void addComponent()
{
    Component newComponent;

    cout << "Iveskite ID: ";
    cin >> newComponent.id;
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i].id == newComponent.id)
        {
            cout << "Komponentas su tokiu ID jau egzistuoja." << endl;
            return;
        }
    }

    cout << "Iveskite gamintoja: ";
    cin >> newComponent.manufacturer;

    cout << "Iveskite modeli: ";
    cin >> newComponent.model;

    cout << "Iveskite tipa: ";
    cin >> newComponent.type;

    cout << "Iveskite kaina: ";
    cin >> newComponent.price;

    components.push_back(newComponent);

    cout << "Komponentas sekmingai pridetas." << endl;
}

void showMenu()
{
    cout << endl;
    cout << "===== PC KOMPONENTU KATALOGAS =====" << endl;
    cout << "1. Rodyti visus komponentus" << endl;
    cout << "2. Prideti komponenta" << endl;
    cout << "3. Redaguoti komponenta" << endl;
    cout << "4. Pasalinti komponenta" << endl;
    cout << "5. Ieskoti pagal gamintoja" << endl;
    cout << "6. Rikiuoti pagal kaina" << endl;
    cout << "7. Issaugoti ir iseiti" << endl;
}

int main()
{
    loadFromFile();

    int choice;

    do
    {
        showMenu();

        cout << "Pasirinkimas: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                showAllComponents();
                break;

            case 2:
                addComponent();
                break;

            case 3:
                cout << "Funkcija dar nesukurta." << endl;
                break;

            case 4:
                cout << "Funkcija dar nesukurta." << endl;
                break;

            case 5:
                cout << "Funkcija dar nesukurta." << endl;
                break;

            case 6:
                cout << "Funkcija dar nesukurta." << endl;
                break;

            case 7:
                cout << "Programa baigiama..." << endl;
                break;

            default:
                cout << "Neteisingas pasirinkimas." << endl;
        }

    } while (choice != 7);

    return 0;
}
