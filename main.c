// 1. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
#include <stdio.h>
void DelSym(char* str, int pos)
{
    for (int i = pos; str[i] != '\0'; i++)
        str[i] = str[i + 1];
}
