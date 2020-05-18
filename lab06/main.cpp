#include <iostream>
using namespace std;

struct ItemInfo
{
    char title[30];
    char manufacturer[150];
    double price;
    int quantity;
};

enum class mainMenu
{
    EXIT, VIEW, ADD, REMOVE
};

enum class sortMenu
{
    BACK, TITLE, MANUFACTURER, QUANTITY
};

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
    if(amount == 1)
    {
        delete[] Obj;
        return nullptr;
    }
    return nullptr;
}

void SetData(ItemInfo *Obj, const size_t amount)
{
    printf(" Title: ");
    scanf_s("%s", Obj[amount].title, _countof(Obj[amount].title));
	
    printf(" Manufacturer: ");
    scanf_s("%s", Obj[amount].manufacturer, _countof(Obj[amount].manufacturer));
	
    printf(" Price: ");
    scanf_s("%lf", &Obj[amount].price);
	
    printf(" Quantity: ");
    scanf_s("%d", &Obj[amount].quantity);
}

void PrintMainMenu()
{
    printf(
        " --------------------\n"
        " | View items  (%d) |\n"
        " | Add item    (%d) |\n"
        " | Remove item (%d) |\n"
        " | Exit        (%d) |\n"
        " --------------------\n",
        mainMenu::VIEW, mainMenu::ADD, mainMenu::REMOVE, mainMenu::EXIT
        );
}

void PrintSortMenu()
{
    printf(
        " ----------------------------\n"
        " | Sort by Title        (%d) |\n"
        " | Sort by Manufacturer (%d) |\n"
        " | Sort by Quantity     (%d) |\n"
        " | Back                 (%d) |\n"
        " ----------------------------\n",
        mainMenu::VIEW, mainMenu::ADD, mainMenu::REMOVE, mainMenu::EXIT
    );
}

void PrintItems(ItemInfo* Obj, size_t amount)
{
    if (amount != 0)
    {
        for (size_t i = 0; i < amount; i++)
        {
            printf(" --\n"
                    " | Index:        %d\n"
                    " | Title:        %s\n"
                    " | Manufacturer: %s\n"
                    " | Price:        %lf\n"
                    " | Quantity:     %d\n",
                        i,
                        Obj->title,
                        Obj->manufacturer, 
                        Obj->price, 
                        Obj->quantity);
        }
        printf(" --\n");
    }
}

int main()
{
    ItemInfo *items = nullptr;
    size_t ItemAmount = 0;
    bool stop_main = false;
    while (!stop_main)
    {
        PrintMainMenu();
        mainMenu main_menu;
        printf(" Option: ");
        scanf_s("%d", &main_menu);
        switch (main_menu)
        {
            case mainMenu::VIEW:
                if (ItemAmount > 0)
                {
                    bool stop_sort = false;
                    while (!stop_sort)
                    {
                        PrintItems(items, ItemAmount);
                        PrintSortMenu();
                        sortMenu sort_menu;
                        printf(" Option: ");
                        scanf_s("%d", &sort_menu);
                        switch (sort_menu)
                        {
                        case sortMenu::TITLE:
                            break;

                        case sortMenu::MANUFACTURER:
                            break;

                        case sortMenu::QUANTITY:
                            break;

                        case sortMenu::BACK:
                            stop_sort = true;
                            break;
                        }
                    }
                }
                else
                {
                    printf(" >> Items amount: %d\n", ItemAmount);
                }
                putchar('\n');
                break;

            case mainMenu::ADD:
                items = AddItem(items, ItemAmount);
                SetData(items, ItemAmount);
        		ItemAmount++;
                break;

            case mainMenu::REMOVE:
                
                break;

            case mainMenu::EXIT:
                stop_main = true;
                break;
        }
    }
    return 0;
}
