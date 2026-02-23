// 1. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
//Tests:
//s1 = "hello world", s2 = "lo" -> "he wrd"
//s1 = "hello world", s2 = "" -> "hello world"
//s1 = "hello", s2 = "hello" -> ""
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
    for (int i = 0; s1[i] != '\0'; )
    {
        if (seen[s1[i]])
            DelSym(s1, i);
        else
            i++;
    }
    printf("%s\n", s1);
}
