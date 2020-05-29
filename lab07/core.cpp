#include "core.h"

void PrintMainMenu(size_t amount)
{
    cout <<
        " --------------------"
        "\n > Items amount: " << amount <<
        "\n --------------------"
        "\n > View items    (" << (size_t)mainMenu::VIEW <<
        ")\n > View one item (" << (size_t)mainMenu::VIEW_ONE <<
        ")\n > Add item      (" << (size_t)mainMenu::ADD <<
        ")\n > Remove item   (" << (size_t)mainMenu::REMOVE <<
        ")\n > Exit          (" << (size_t)mainMenu::EXIT <<
        ")\n --------------------" << endl;
}
void PrintSortMenu(size_t amount)
{
    cout <<
        " ---------------------------"
        "\n > Items amount:         " << amount <<
        "\n ---------------------------"
        "\n > Sort by Title        (" << (size_t)sortMenu::TITLE <<
        ")\n > Sort by Manufacturer (" << (size_t)sortMenu::MANUFACTURER <<
        ")\n > Sort by Price        (" << (size_t)sortMenu::PRICE <<
        ")\n > Sort by Quantity     (" << (size_t)sortMenu::QUANTITY <<
        ")\n > Back                 (" << (size_t)sortMenu::BACK <<
        ")\n ---------------------------" << endl;
}
void AddItem(char* path)
{
    ofstream fout(path, ios::app);
    ItemInfo item;
    
    cout << " Title: ";
    cin.getline(item.title, _countof(item.title));

    cout << " Manufacturer: ";
    cin.getline(item.manufacturer, _countof(item.manufacturer));

    cout << " Price: ";
    cin >> item.price;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << " Quantity: ";
    cin >> item.quantity;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    putStruct(fout, item);
    fout.close();
}
void RemoveItem(char* path, size_t index)
{
    size_t amount = getAmount(path);
    if (amount > 0)
    {
        char tmp_path[140];
        tmp_path[0] = '\0';
        strcat_s(tmp_path, path);
        strcat_s(tmp_path, ".tmpremove");

        ifstream fin(path);
        ofstream fout(tmp_path, ios::trunc);
        ItemInfo item;
        for (size_t i = 0; getStruct(fin, item); i++) {
            
            if (i != index) {
                putStruct(fout, item);
            }
        }
        fin.close();
        fout.close();
        remove(path);
        rename(tmp_path, path);
    }
}
int PrintItem(char* path, size_t index) {
    ifstream fin(path);
    if (!fin)
        return -1;
    ItemInfo item;
    for (size_t i = 0; i <= index; i++)
    {
        getStruct(fin, item);
    }
    cout <<
        "\n ---------------------------"
        "\n > Index:        " << index             <<
        "\n > Title:        " << item.title        <<
        "\n > Manufacturer: " << item.manufacturer <<
        "\n > Price:        " << item.price        <<
        "\n > Quantity:     " << item.quantity     << 
        "\n ---------------------------"           << endl << endl;
    return 0;
}
int PrintItems(char *path)
{
    ifstream fin(path);
    if (!fin) 
        return -1;
    ItemInfo item;
    for (size_t i = 0; getStruct(fin, item); i++)
    {
        cout <<
            " ---------------------------"
            "\n > Index:        " << i                   <<
            "\n > Title:        " << item.title        <<
            "\n > Manufacturer: " << item.manufacturer <<
            "\n > Price:        " << item.price        <<
            "\n > Quantity:     " << item.quantity     << endl;
    }
    fin.close();
    return 0;
}
void SortByTitle(char* path)
{
    size_t amount = getAmount(path);
    char tmp_path[139];
    tmp_path[0] = '\0';
    strcat_s(tmp_path, path);
    strcat_s(tmp_path, ".tmptsort");

    ofstream fout(tmp_path, ios::app);
    ItemInfo seconditem, minitem;
    for (size_t i = 0; i < amount-1; i++) {
        size_t minindex = 0;
        ifstream fin(path);
        getStruct(fin, minitem);
        for (size_t j = 1; getStruct(fin, seconditem); j++) {
            if (strcmp(minitem.title, seconditem.title) > 0) {
                minitem = seconditem;
                minindex = j;
            }
        }
        fin.close();
        putStruct(fout, minitem);
        RemoveItem(path, minindex);
    }
    ifstream fin(path, ios::app);
    getStruct(fin, minitem);
    putStruct(fout, minitem);
    fin.close();
    fout.close();
    
    remove(path);
    rename(tmp_path, path);
}
void SortByManufacturer(char* path)
{
    size_t amount = getAmount(path);
    char tmp_path[139];
    tmp_path[0] = '\0';
    strcat_s(tmp_path, path);
    strcat_s(tmp_path, ".tmpmsort");

    ofstream fout(tmp_path, ios::app);
    ItemInfo seconditem, minitem;
    for (size_t i = 0; i < amount - 1; i++) {
        size_t minindex = 0;
        ifstream fin(path);
        getStruct(fin, minitem);
        for (size_t j = 1; getStruct(fin, seconditem); j++) {
            if (strcmp(minitem.manufacturer, seconditem.manufacturer) > 0) {
                minitem = seconditem;
                minindex = j;
            }
        }
        fin.close();
        putStruct(fout, minitem);
        RemoveItem(path, minindex);
    }
    ifstream fin(path, ios::app);
    getStruct(fin, minitem);
    putStruct(fout, minitem);
    fin.close();
    fout.close();

    remove(path);
    rename(tmp_path, path);
}
void SortByPrice(char* path)
{
    size_t amount = getAmount(path);
    char tmp_path[139];
    tmp_path[0] = '\0';
    strcat_s(tmp_path, path);
    strcat_s(tmp_path, ".tmppsort");

    ofstream fout(tmp_path, ios::app);
    ItemInfo seconditem, minitem;
    for (size_t i = 0; i < amount - 1; i++) {
        size_t minindex = 0;
        ifstream fin(path);
        getStruct(fin, minitem);
        for (size_t j = 1; getStruct(fin, seconditem); j++) {
            if (minitem.price > seconditem.price) {
                minitem = seconditem;
                minindex = j;
            }
        }
        fin.close();
        putStruct(fout, minitem);
        RemoveItem(path, minindex);
    }
    ifstream fin(path, ios::app);
    getStruct(fin, minitem);
    putStruct(fout, minitem);
    fin.close();
    fout.close();

    remove(path);
    rename(tmp_path, path);
}
void SortByQuantity(char* path)
{
    size_t amount = getAmount(path);
    char tmp_path[139];
    tmp_path[0] = '\0';
    strcat_s(tmp_path, path);
    strcat_s(tmp_path, ".tmpqsort");

    ofstream fout(tmp_path, ios::app);
    ItemInfo seconditem, minitem;
    for (size_t i = 0; i < amount - 1; i++) {
        size_t minindex = 0;
        ifstream fin(path);
        getStruct(fin, minitem);
        for (size_t j = 1; getStruct(fin, seconditem); j++) {
            if (minitem.quantity > seconditem.quantity) {
                minitem = seconditem;
                minindex = j;
            }
        }
        fin.close();
        putStruct(fout, minitem);
        RemoveItem(path, minindex);
    }
    ifstream fin(path, ios::app);
    getStruct(fin, minitem);
    putStruct(fout, minitem);
    fin.close();
    fout.close();

    remove(path);
    rename(tmp_path, path);
}
bool getStruct(ifstream &fin, ItemInfo &item) {
    if (fin.peek() == -1) return false;

    //get title
    fin.getline(item.title, _countof(item.title) - 1, '|');
    
    //get manufacturer
    fin.getline(item.manufacturer, _countof(item.manufacturer) - 1, '|');
    
    //get price
    fin >> item.price;
    fin.get();

    //get quantity
    fin >> item.quantity;
    fin.get();
    return 1;
}
void putStruct(ofstream &fout, ItemInfo &item) {
    fout << item.title << '|' << item.manufacturer << '|' << item.price << '|' << item.quantity << endl;
}
size_t getAmount(char* path) {
    size_t amount = 0;
    ItemInfo item;
    ifstream fin(path);
    if (!fin) return amount;
    while (getStruct(fin, item)) {
        amount++;
    }
    fin.close();
    return amount;
}
