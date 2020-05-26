#pragma once                                                                              
                                                                                          
struct     ItemInfo                                                                       
{                                                                                         
    char   title[32];                                                                     
    char   manufacturer[64];                                                              
    double price;                                                                         
    size_t quantity;                                                                      
};                                                                                        
enum class mainMenu                                                                       
{                                                                                         
    EXIT     ,                                                                            
    VIEW     ,                                                                            
    VIEW_ONE ,                                                                            
    ADD      ,                                                                            
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
ItemInfo*  AddItem            ( ItemInfo* Obj, const size_t  amount                       );
ItemInfo*  RemoveItem         ( ItemInfo* Obj, const size_t  amount, const size_t index   );
void       SetData            ( ItemInfo* Obj, const size_t  amount                       );
void       PrintMainMenu      (                const size_t  amount                       );
void       PrintSortMenu      (                const size_t  amount                       );
void       PrintItem          ( ItemInfo* Obj, const size_t  index,  const size_t amount  );
void       PrintItems         ( ItemInfo* Obj, const size_t  amount                       );
void       Swap               ( ItemInfo* Obj, const size_t  x,      const size_t y       );
void       SortByTitle        ( ItemInfo* Obj, const size_t  amount                       );
void       SortByManufacturer ( ItemInfo* Obj, const size_t  amount                       );
void       SortByPrice        ( ItemInfo* Obj, const size_t  amount                       );
void       SortByQuantity     ( ItemInfo* Obj, const size_t  amount                       );
void       SaveToFile         ( ItemInfo* Obj, const size_t  amount, const char* filename );
ItemInfo*  LoadFromFile       (                      size_t* amount, const char* filename );
