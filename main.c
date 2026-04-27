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

void DelSym(char *str, size_t strbuf_size, size_t rmbuf_size, const char *to_remove)
{
    if (str == NULL || to_remove == NULL || strbuf_size == 0 || rmbuf_size == 0)
        return;

    bool seen[256] = { false };

    for (size_t j = 0; j < rmbuf_size && to_remove[j] != '\0'; j++)
    {
        if ((unsigned char)to_remove[j] > 127)
        {
            printf("Russian characters are not supported in s2\n");
            return;
        }
        seen[(unsigned char)to_remove[j]] = true;
    }

    size_t write = 0;
    size_t read = 0;

    while (read < strbuf_size && str[read] != '\0')
    {
        if ((unsigned char)str[read] > 127)
        {
            printf("Russian characters are not supported in s1\n");
            return;
        }

        if (!seen[(unsigned char)str[read]])
        {
            if (write < strbuf_size - 1)
            {
                str[write++] = str[read];
            }
        }
        read++;
    }

    if (write < strbuf_size)
    {
        str[write] = '\0';
    }
    else if (strbuf_size > 0)
    {
        str[strbuf_size - 1] = '\0';
    }
}

int main()
{
    char s1[MAX_S1_LEN] = "пр";
    char s2[MAX_S2_LEN] = "lo";
    DelSym(s1, sizeof(s1), sizeof(s2), s2);
    printf("%s\n", s1);
    return 0;
}
