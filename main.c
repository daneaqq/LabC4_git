// 1. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
//Tests:
//s1 = "hello world", s2 = "lo" -> "he wrd"
//s1 = "hello world", s2 = "" -> "hello world"
//s1 = "hello", s2 = "hello" -> ""
//s1 = "привет", s2 = "ет" -> bad input or null pointer

#include <stdio.h>
#include <stdbool.h>

#define MAX_S1_LEN 1000
#define MAX_S2_LEN 1000

int DelSym(char *str, size_t strbuf_size, size_t rmbuf_size, const char *to_remove)
{
    if (str == NULL || to_remove == NULL || strbuf_size == 0 || rmbuf_size == 0)
        return -1;

    bool seen[256] = { false };
    for (size_t j = 0; j < rmbuf_size && to_remove[j] != '\0'; j++)
    {
        if (to_remove[j] < 0)
            return -2;
        seen[(unsigned char)to_remove[j]] = true;
    }

    size_t write = 0;
    size_t read = 0;

    while (read < strbuf_size && str[read] != '\0')
    {
        if (str[read] < 0)
            return -2;

        if (!seen[str[read]])
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
  return 0;
}

int main()
{
    char s1[MAX_S1_LEN] = "рello";
    char s2[MAX_S2_LEN] = "l";
    if (DelSym(s1, sizeof(s1), sizeof(s2), s2) < 0)
      printf("bad input or null pointer\n");
    else
      printf("%s\n", s1);
    return 0;
}
