#pragma once                                                                              
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct     ItemInfo                                                                       
{                                                                                         
    char   title[64];                                                                     
    char   manufacturer[64];                                                              
    double price;                                                                         
    size_t quantity;                                                                      
};                                                                                        
enum class mainMenu
{
    EXIT,
    VIEW,
    VIEW_ONE,
    ADD,
    REMOVE
};
enum class sortMenu
{
    BACK         ,
    TITLE        ,
    MANUFACTURER ,
    PRICE        ,
    QUANTITY
};

void   PrintMainMenu      ( size_t       amount                       );
void   PrintSortMenu      ( size_t       amount                       );
void   AddItem            ( char*        path                         );
void   RemoveItem         ( char*        path,     size_t       index );
int    PrintItem          ( char*        path,     size_t       index );
int    PrintItems         ( char*        path                         );
void   SortByTitle        ( char*        path                         );
void   SortByManufacturer ( char*        path                         );
void   SortByPrice        ( char*        path                         );
void   SortByQuantity     ( char*        path                         );
bool   getStruct          ( ifstream&    fin ,     ItemInfo&    item  );
void   putStruct          ( ofstream&    fout,     ItemInfo&    item  );
size_t getAmount          ( char*        path                         );
