#include <iostream>

struct ItemInfo
{
    char title[30];
    char manufacturer[150];
    double price;
    unsigned int quantity;
};

enum class mainMenu
{
    EXIT, VIEW, ADD, REMOVE
};

enum class sortMenu
{
    BACK, TITLE, MANUFACTURER, PRICE, QUANTITY
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
    if (amount == 1)
    {
        delete[] Obj;
        return nullptr;
    }
    return nullptr;
}

void SetData(ItemInfo* Obj, const size_t amount)
{
    printf(" Title: ");
    scanf_s("%s", Obj[amount].title, _countof(Obj[amount].title));

    printf(" Manufacturer: ");
    scanf_s("%s", Obj[amount].manufacturer, _countof(Obj[amount].manufacturer));

    printf(" Price: ");
    scanf_s("%lf", &Obj[amount].price);

    printf(" Quantity: ");
    scanf_s("%u", &Obj[amount].quantity);
}

void PrintMainMenu(const size_t amount)
{
    printf(
        " -------------------\n"
        " > Items amount: %u\n"
        " -------------------\n"
        " > View items   (%d)\n"
        " > Add item     (%d)\n"
        " > Remove item  (%d)\n"
        " > Exit         (%d)\n"
        " -------------------\n",
        amount, mainMenu::VIEW, mainMenu::ADD, mainMenu::REMOVE, mainMenu::EXIT
    );
}

void PrintSortMenu(const size_t amount)
{
    printf(
        " ----------------------------\n"
        " > Items amount:         %u\n"
        " ----------------------------\n"
        " > Sort by Title        (%d)\n"
        " > Sort by Manufacturer (%d)\n"
        " > Sort by Price        (%d)\n"
        " > Sort by Quantity     (%d)\n"
        " > Back                 (%d)\n"
        " ----------------------------\n",
        amount ,sortMenu::TITLE, sortMenu::MANUFACTURER, sortMenu::PRICE, sortMenu::QUANTITY, sortMenu::BACK
    );
}

void PrintItems(ItemInfo* Obj, const size_t amount)
{
    if (amount != 0)
    {
        for (size_t i = 0; i < amount; i++)
        {
            printf(" ----------------------------\n"
                " > Index:        %d\n"
                " > Title:        %s\n"
                " > Manufacturer: %s\n"
                " > Price:        %lf\n"
                " > Quantity:     %d\n",
                i,
                Obj[i].title,
                Obj[i].manufacturer,
                Obj[i].price,
                Obj[i].quantity);
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

}

void SortByManufacturer(ItemInfo* Obj, const size_t amount)
{
    
}

void SortByPrice(ItemInfo* Obj, const size_t amount)
{
    for (size_t i = 0; i < amount-1; i++)
    {
        for (size_t j = i+1; j < amount; j++)
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


int main()
{
    ItemInfo* Items = nullptr;
    size_t ItemsAmount = 0;
    bool stop_main = false;
    while (!stop_main)
    {
        system("cls");
        PrintMainMenu(ItemsAmount);
        mainMenu main_menu;
        size_t index = 0;
        printf(" Option: ");
        scanf_s("%d", &main_menu);
        switch (main_menu)
        {
        case mainMenu::VIEW:
            if (ItemsAmount > 0)
            {
                bool stop_sort = false;
                while (!stop_sort)
                {
                    system("cls");
                    PrintItems(Items, ItemsAmount);
                    PrintSortMenu(ItemsAmount);
                    sortMenu sort_menu;
                    printf(" Option: ");
                    scanf_s("%d", &sort_menu);
                    switch (sort_menu)
                    {
                    case sortMenu::TITLE:
                        SortByTitle(Items, ItemsAmount);
                        break;

                    case sortMenu::MANUFACTURER:
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
                putchar('\n');
            }
            break;

        case mainMenu::ADD:
            Items = AddItem(Items, ItemsAmount);
            SetData(Items, ItemsAmount);
            ItemsAmount++;
            break;

        case mainMenu::REMOVE:
            printf(" Item index: ");
            scanf_s("%u", &index);
            Items = RemoveItem(Items, ItemsAmount, index);
            ItemsAmount--;
            break;

        case mainMenu::EXIT:
            stop_main = true;
            break;
        }
    }
    return 0;
}
