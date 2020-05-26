#include <iostream>
#include <fstream>
#include "core.h"
using namespace std;

ItemInfo* AddItem(ItemInfo* Obj, const size_t amount)
{
    if (amount == 0)
    {
        Obj = new ItemInfo[amount + 1](); // выделение памяти для первой структуры
    }
    else
    {
        ItemInfo* tempObj = new ItemInfo[amount + 1]();
        for (size_t i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;
        Obj = tempObj;
    }
    return Obj;
}
ItemInfo* RemoveItem(ItemInfo* Obj, const size_t amount, const size_t index)
{
    if (amount > 1)
    {
        ItemInfo* items = new ItemInfo[(amount)-1]();
        for (size_t i = 0; i < amount; i++)
        {
            if (i < index) items[i] = Obj[i];
            if (i > index) items[i - 1] = Obj[i];
        }
        delete[] Obj;
        Obj = items;
        return Obj;
    }
    if (amount == 1)
    {
        delete[] Obj;
        return nullptr;
    }
    return nullptr;
}
void SetData(ItemInfo* Obj, const size_t amount)
{
    cout << " Title: ";
    cin.getline(Obj[amount].title, _countof(Obj[amount].title));
    
    cout << " Manufacturer: ";
    cin.getline(Obj[amount].manufacturer, _countof(Obj[amount].manufacturer));

    cout << " Price: ";
    cin >> Obj[amount].price;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << " Quantity: ";
    cin >> Obj[amount].quantity;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void PrintMainMenu(const size_t amount)
{
    cout <<
        " --------------------"
        "\n > Items amount:  " << amount                     <<
        "\n --------------------"
        "\n > View items    ("  << (size_t)mainMenu::VIEW     <<
        ")\n > View one item ("  << (size_t)mainMenu::VIEW_ONE <<
        ")\n > Add item      ("  << (size_t)mainMenu::ADD      <<
        ")\n > Remove item   ("  << (size_t)mainMenu::REMOVE   <<
        ")\n > Exit          ("  << (size_t)mainMenu::EXIT     <<
        ")\n --------------------" << endl;
}
void PrintSortMenu(const size_t amount)
{
    cout <<
        " ---------------------------"
        "\n > Items amount:         " << amount <<
        "\n ---------------------------"
        "\n > Sort by Title        ("  << (size_t)sortMenu::TITLE <<
        ")\n > Sort by Manufacturer ("  << (size_t)sortMenu::MANUFACTURER <<
        ")\n > Sort by Price        ("  << (size_t)sortMenu::PRICE <<
        ")\n > Sort by Quantity     ("  << (size_t)sortMenu::QUANTITY <<
        ")\n > Back                 ("  << (size_t)sortMenu::BACK <<
        ")\n ---------------------------" << endl;
}
void PrintItem(ItemInfo* Obj, const size_t index, const size_t amount) {
    if (amount > 0 && index >= 0 && index < amount)
    {
        cout <<
            " ---------------------------"
            "\n > Index:        " << index <<
            "\n > Title:        " << Obj[index].title <<
            "\n > Manufacturer: " << Obj[index].manufacturer <<
            "\n > Price:        " << Obj[index].price <<
            "\n > Quantity:     " << Obj[index].quantity << endl;

    }
}
void PrintItems(ItemInfo* Obj, const size_t amount)
{
    if (amount != 0)
    {
        for (size_t i = 0; i < amount; i++)
        {
            cout <<
                " ---------------------------"
                "\n > Index:        " << i                   <<
                "\n > Title:        " << Obj[i].title        <<
                "\n > Manufacturer: " << Obj[i].manufacturer <<
                "\n > Price:        " << Obj[i].price        <<
                "\n > Quantity:     " << Obj[i].quantity     << endl;
        }
    }
}
void Swap(ItemInfo* Obj, const size_t x, const size_t y)
{
    const ItemInfo temp = Obj[x];
    Obj[x] = Obj[y];
    Obj[y] = temp;
}
void SortByTitle(ItemInfo* Obj, const size_t amount)
{
    for (size_t i = 0; i < amount - 1; i++)
    {
        for (size_t j = i + 1; j < amount; j++)
        {
            if (strcmp(Obj[i].title, Obj[j].title) > 0) Swap(Obj, i, j);
        }
    }
}
void SortByManufacturer(ItemInfo* Obj, const size_t amount)
{
    for (size_t i = 0; i < amount - 1; i++)
    {
        for (size_t j = i + 1; j < amount; j++)
        {
            if (std::strcmp(Obj[i].manufacturer, Obj[j].manufacturer) > 0) Swap(Obj, i, j);
        }
    }
}
void SortByPrice(ItemInfo* Obj, const size_t amount)
{
    for (size_t i = 0; i < amount - 1; i++)
    {
        for (size_t j = i + 1; j < amount; j++)
        {
            if (Obj[j].price < Obj[i].price) Swap(Obj, i, j);
        }
    }
}
void SortByQuantity(ItemInfo* Obj, const size_t amount)
{
    for (size_t i = 0; i < amount - 1; i++)
    {
        for (size_t j = i + 1; j < amount; j++)
        {
            if (Obj[j].quantity < Obj[i].quantity) Swap(Obj, i, j);
        }
    }
}
void SaveToFile(ItemInfo* Obj, const size_t amount, const char* filename) {
    ofstream fout(filename, ios::trunc | ios::binary);
    fout << amount << endl;
    if (amount > 0)
        for (size_t i = 0; i < amount; i++) {
            fout << Obj[i].title << "\n" << Obj[i].manufacturer << "\n" << Obj[i].price << "\n" << Obj[i].quantity << endl;
        }
    fout.close();

}
ItemInfo* LoadFromFile(size_t* amount, const char* filename) {
    ifstream fin(filename);
    if (!fin) return nullptr;
    fin >> *amount;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    ItemInfo* Obj = new ItemInfo[*amount];
    for (size_t i = 0; i < *amount; i++)
    {
        fin.getline(Obj[i].title, _countof(Obj[i].title));
        fin.getline(Obj[i].manufacturer, _countof(Obj[i].manufacturer));
        fin >> Obj[i].price;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
        fin >> Obj[i].quantity;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    fin.close();
    return Obj;
}
