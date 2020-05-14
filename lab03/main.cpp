#include <stdio.h>
#define MAXLENGTH 12

int main() {
    int mas[MAXLENGTH];
    for (size_t i = 0; i < MAXLENGTH; i++) mas[i] = 200 + i * 12;
    //======================================================================================
    for (size_t i = 0; i < MAXLENGTH; i++)
    {
        if (mas[i] % 2 == 0) {
            mas[i] = (mas[i] / 100) * 10 + (mas[i] % 10) + ((mas[i] % 100) / 10) * 100;
        }
        else {
            mas[i] = (mas[i] / 100) + (mas[i] % 10) * 10 + ((mas[i] % 100) / 10) * 100;
        }
    }
    //======================================================================================
    for (size_t i = 0; i < MAXLENGTH; i++)
    {
        if (mas[i]<10 && mas[i]>-10) printf("00%d; ", mas[i]);
        else if (mas[i]<100 && mas[i]>-100) printf("0%d; ", mas[i]);
        else printf("%d; ", mas[i]);
    }

    return 0;
}
