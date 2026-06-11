#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

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

    cout << left;
    cout << setw(5) << "ID"
         << setw(15) << "Gamintojas"
         << setw(25) << "Modelis"
         << setw(15) << "Tipas"
         << setw(10) << "Kaina" << endl;

    cout << "-----------------------------------------------------------------" << endl;

    for (int i = 0; i < components.size(); i++)
    {
        cout << setw(5) << components[i].id
             << setw(15) << components[i].manufacturer
             << setw(25) << components[i].model
             << setw(15) << components[i].type
             << setw(10) << components[i].price
             << endl;
    }
}

void addComponent()
{
    Component newComponent;

    cout << "Iveskite ID: ";
    cin >> newComponent.id;

    // Patikriname, ar toks ID jau neegzistuoja
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
    cout << "\n======================================" << endl;
    cout << "      PC KOMPONENTU KATALOGAS" << endl;
    cout << "======================================" << endl;
    cout << "1. Rodyti visus komponentus" << endl;
    cout << "2. Prideti komponenta" << endl;
    cout << "3. Redaguoti komponenta" << endl;
    cout << "4. Pasalinti komponenta" << endl;
    cout << "5. Ieskoti pagal gamintoja" << endl;
    cout << "6. Rikiuoti pagal kaina" << endl;
    cout << "7. Iseiti" << endl;
    cout << "======================================" << endl;
}

void saveToFile()
{
    ofstream file("components.txt");

    for (int i = 0; i < components.size(); i++)
    {
        file << components[i].id << ";";
        file << components[i].manufacturer << ";";
        file << components[i].model << ";";
        file << components[i].type << ";";
        file << components[i].price << endl;
    }

    file.close();
}

void deleteComponent()
{
    int idToDelete;

    cout << "Iveskite komponento ID: ";
    cin >> idToDelete;

    for (int i = 0; i < components.size(); i++)
    {
        if (components[i].id == idToDelete)
        {
            components.erase(components.begin() + i);

            cout << "Komponentas sekmingai pasalintas." << endl;

            return;
        }
    }

    cout << "Komponentas nerastas." << endl;
}

void updateComponent()
{
    int idToUpdate;

    cout << "Iveskite komponento ID: ";
    cin >> idToUpdate;

    for (int i = 0; i < components.size(); i++)
    {
        if (components[i].id == idToUpdate)
        {
            cout << "Iveskite nauja gamintoja: ";
            cin >> components[i].manufacturer;

            cout << "Iveskite nauja modeli: ";
            cin >> components[i].model;

            cout << "Iveskite nauja tipa: ";
            cin >> components[i].type;

            cout << "Iveskite nauja kaina: ";
            cin >> components[i].price;

            cout << "Komponentas sekmingai atnaujintas." << endl;

            return;
        }
    }

    cout << "Komponentas nerastas." << endl;
}

void searchByManufacturer()
{
    string manufacturer;
    bool found = false;

    cout << "Iveskite gamintoja: ";
    cin >> manufacturer;

    for (int i = 0; i < components.size(); i++)
    {
        if (components[i].manufacturer == manufacturer)
        {
            cout << "ID: " << components[i].id << endl;
            cout << "Gamintojas: " << components[i].manufacturer << endl;
            cout << "Modelis: " << components[i].model << endl;
            cout << "Tipas: " << components[i].type << endl;
            cout << "Kaina: " << components[i].price << " EUR" << endl;
            cout << "------------------------" << endl;

            found = true;
        }
    }

    if (found == false)
    {
        cout << "Komponentu su tokiu gamintoju nerasta." << endl;
    }
}

void sortByPrice()
{
    for (int i = 0; i < components.size() - 1; i++)
    {
        for (int j = 0; j < components.size() - 1 - i; j++)
        {
            if (components[j].price > components[j + 1].price)
            {
                Component temp = components[j];
                components[j] = components[j + 1];
                components[j + 1] = temp;
            }
        }
    }

    cout << "Komponentai surikiuoti pagal kaina." << endl;

    showAllComponents();
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
                updateComponent();
                break;

            case 4:
                deleteComponent();
                break;

            case 5:
                searchByManufacturer();
                break;

            case 6:
                sortByPrice();
                break;

            case 7:
                saveToFile();
                cout << "Programa baigiama..." << endl;
                break;

            default:
                cout << "Neteisingas pasirinkimas." << endl;
        }

    } while (choice != 7);

    return 0;
}
