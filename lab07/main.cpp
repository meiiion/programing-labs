#include <iostream>
#include "core.h"
using namespace std;

int main(int argc, char *argv[])
{
    char path[128] = "C:\\items.dat";
    if (argc == 2) {
        size_t i = 0;
        for (; i<128 && argv[1][i] != '\0'; i++)
        {
            path[i] = argv[1][i];
        }
        path[i] = '\0';
    }
    bool stop_main = false;
    while (!stop_main)
    {
        system("cls");
        size_t ItemsAmount = getAmount(path);
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
                    PrintItems(path);
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
                        SortByTitle(path);
                        break;

                    case sortMenu::MANUFACTURER:
                        SortByManufacturer(path);
                        break;

                    case sortMenu::PRICE:
                        SortByPrice(path);
                        break;
                    case sortMenu::QUANTITY:
                        SortByQuantity(path);
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
            if (index < 0 || index >= ItemsAmount) cout << " Encorrect index" << endl;
            else {
                PrintItem(path, index);
            }
            system("pause");
            break;
        case mainMenu::ADD:
            cout << "\n---------------------\n Data for new item\n---------------------" << endl;
            AddItem(path);
            break;

        case mainMenu::REMOVE:
            cout << " Item index: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            RemoveItem(path, index);
            break;

        case mainMenu::EXIT:
            stop_main = true;
            break;
        }
    }
    return 0;
}
