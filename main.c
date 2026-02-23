// 1. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
#include <stdio.h>
void DelSym(char* str, int pos)
{
    for (int i = pos; str[i] != '\0'; i++)
        str[i] = str[i + 1];
}
int main()
{
    char s1[1000] = "hello world";
    char s2[1000] = "lo";
    char seen[256] = { 0 };
    for (int j = 0; s2[j] != '\0'; j++)
        seen[s2[j]] = 1;
}
