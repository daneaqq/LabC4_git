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
        seen[(int)to_remove[j]] = true;
    }

    size_t write = 0;
    size_t read = 0;

    while (read < strbuf_size && str[read] != '\0')
    {
        if (str[read] < 0)
            return -2;

        if (!seen[(int)str[read]])
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
    char s1[MAX_S1_LEN] = "hello";
    char s2[MAX_S2_LEN] = "l";
    // char s1[MAX_S1_LEN] = "hello";
    // char s2[MAX_S2_LEN] = "xyz";
    // char s1[MAX_S1_LEN] = "hello";
    // char s2[MAX_S2_LEN] = "hello";
    // char s1[MAX_S1_LEN] = "space test";
    // char s2[MAX_S2_LEN] = " ";
    // char s1[MAX_S1_LEN] = "12345";
    // char s2[MAX_S2_LEN] = "24";
    // char s1[MAX_S1_LEN] = "";
    // char s2[MAX_S2_LEN] = "abc";
    // char s1[MAX_S1_LEN] = "abc";
    // char s2[MAX_S2_LEN] = "";
    // char s1[MAX_S1_LEN] = "";
    // char s2[MAX_S2_LEN] = "";
    // char s1[2] = "a";
    // char s2[2] = "a";
    if (DelSym(s1, sizeof(s1), sizeof(s2), s2) < 0)
      printf("bad input or null pointer\n");
    else
      printf("%s\n", s1);
    return 0;
}
