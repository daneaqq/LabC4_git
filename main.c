// 1. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
//Tests:
//s1 = "hello world", s2 = "lo" -> "he wrd"
//s1 = "hello world", s2 = "" -> "hello world"
//s1 = "hello", s2 = "hello" -> ""
//s1 = "привет", s2 = "ет" -> Russian characters are not supported
#include <stdio.h>
#include <stdbool.h>

#define MAX_S1_LEN 1000
#define MAX_S2_LEN 1000

void DelSym(char *str, size_t buf_size, const char *to_remove)
{
    if (str == NULL || to_remove == NULL || buf_size == 0)
    {
        return;
    }
    size_t len = 0;
    while (len < buf_size && str[len] != '\0') len++;
    {
    if (len >= buf_size)
      return;
    }
    bool seen[256] = { false };
    for (int j = 0; to_remove[j]; j++)
    {
        seen[(unsigned char)to_remove[j]] = true;
    }
    int write = 0;
    for (int read = 0; str[read] && write < (int)buf_size - 1; read++)
    {
      if (!seen[(unsigned char)str[read]])
        str[write++] = str[read];
    }
    str[write] = '\0';
}

int main()
{
    char s1[MAX_S1_LEN] = "hello world";
    char s2[MAX_S2_LEN] = "lo";

    for (int i = 0; s1[i] != '\0'; i++)
    {
        if ((unsigned char)s1[i] > 127)
        {
            printf("Russian characters are not supported\n");
            return 0;
        }
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if ((unsigned char)s2[i] > 127)
        {
            printf("Russian characters are not supported\n");
            return 0;
        }
    }

    DelSym(s1,sizeof(s1),s2);

    printf("%s\n", s1);
    return 0;
}

