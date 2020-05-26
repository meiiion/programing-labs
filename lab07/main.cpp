#include <iostream>
#include "core.h"
const char path[] = "C:\\items.data";
using namespace std;

int main(int argc, char *argv[])
{
    size_t ItemsAmount = 0;
    ItemInfo* Items = LoadFromFile(&ItemsAmount, path);
    bool stop_main = false;
    while (!stop_main)
    {
        system("cls");
        PrintMainMenu(ItemsAmount);
        size_t index = 0;
        cout << " Option: ";
        int main_opt = 0;
        cin >> main_opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (main_opt > 4 || main_opt < 0) {
            cout << " Encorrect option: " << main_opt << endl;
            system("pause");
            continue;
        }
        mainMenu main_menu = (mainMenu)main_opt;
        switch (main_menu) {
        case mainMenu::VIEW:
            if (ItemsAmount > 0)
            {
                bool stop_sort = false;
                while (!stop_sort)
                {
                    system("cls");
                    PrintItems(Items, ItemsAmount);
                    PrintSortMenu(ItemsAmount);
                    cout << " Option: ";
                    int sort_opt = 0;
                    cin >> sort_opt;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (sort_opt > 4 || sort_opt < 0) {
                        cout << " Encorrect option: " << sort_opt<< endl;
                        system("pause");
                        continue;
                    }
                    sortMenu sort_menu = (sortMenu)sort_opt;
                    switch (sort_menu)
                    {
                    case sortMenu::TITLE:
                        SortByTitle(Items, ItemsAmount);
                        break;

                    case sortMenu::MANUFACTURER:
                        SortByManufacturer(Items, ItemsAmount);
                        break;

                    case sortMenu::PRICE:
                        SortByPrice(Items, ItemsAmount);
                        break;
                    case sortMenu::QUANTITY:
                        SortByQuantity(Items, ItemsAmount);
                        break;

                    case sortMenu::BACK:
                        stop_sort = true;
                        break;
                    }
                }
                cout << endl;
            }
            if (ItemsAmount == 0) {
                cout << " Items amount: 0" << endl;
                system("pause");
            }
            break;
        case mainMenu::VIEW_ONE:
            if (ItemsAmount == 0) {
                cout << " Items amount: 0" << endl;
                system("pause");
                break;
            }
            system("cls");
            cout << " Index: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (index < 0 || index > ItemsAmount) cout << " Encorrect index" << endl;
            else {
                PrintItem(Items, index, ItemsAmount);
            }
            system("pause");
            break;
        case mainMenu::ADD:
            cout << "\n---------------------\n Data for new item\n---------------------" << endl;
            Items = AddItem(Items, ItemsAmount);
            SetData(Items, ItemsAmount);
            ItemsAmount++;
            break;

        case mainMenu::REMOVE:
            cout << " Item index: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Items = RemoveItem(Items, ItemsAmount, index);
            ItemsAmount--;
            break;

        case mainMenu::EXIT:
            stop_main = true;
            break;
        }
        SaveToFile(Items, ItemsAmount, path);
    }
    return 0;
}
