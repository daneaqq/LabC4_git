// 1. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
//Tests:
//s1 = "hello world", s2 = "lo" -> "he wrd"
//s1 = "hello world", s2 = "" -> "hello world"
//s1 = "hello", s2 = "hello" -> ""
//s1 = "привет", s2 = "ет" -> Russian characters are not supported

#include <stdio.h>
#define MAX_S1_LEN 1000
#define MAX_S2_LEN 1000
int DelSym(char* str, int pos)
{
    if (str == NULL)
      return -1;
    for (int i = pos; str[i] != '\0'; i++)
        str[i] = str[i + 1];
    return 0;
}
int main()
{
    char s1[MAX_S1_LEN] = "hello world";
    char s2[MAX_S2_LEN] = "lo";
    char seen[256] = { 0 };
    for (int i = 0; s1[i] || s2[i]; i++)
    if (((unsigned char)s1[i] > 127) || ((unsigned char)s2[i] > 127))
    {
        printf("Russian characters are not supported\n");
        return 0;
    }
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
