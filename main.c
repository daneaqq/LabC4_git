// 3. Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, пробел,
// за последним словом – точка. Напечатать все слова из списка, отличные от заданного слова W.
//Tests:
// input: "abc, bca, bac.", w: "bca" output: abc bac
// input: "bca, bca, bca.", w: "bca" output: нет отличных слов
// input: "abc,  bca  ,  bac  .", w: "bca" output: abc bac
// input: "abc,,,bca,,,bac.", w: "bca" output: abc bac
#include <stdio.h>
#include <string.h>
#define MAX_INPUT_LEN 1000
#define MAX_W_LEN 100
int cmpstr(const char *s1, const char *s2, int n)
{
    if (s1 == NULL || s2 == NULL)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return 1;
        if (s1[i] == '\0')
            break;
    }
    return 0;
}

int main()
{
    char input[MAX_INPUT_LEN] = "abc, bca, bac";
    char w[MAX_W_LEN] = "bca";
    char *p = input;
    int found = 0;
    int w_len = strlen(w);

    while (*p != '.' && *p != '\0')
    {
        while (*p == ' ' || *p == ',') p++;
        if (*p == '.')
          break;

        char *start = p;
        while (*p != '.' && *p != ',' && *p != ' ' && *p != '\0')
          p++;

        int len = p - start;

        if (len != w_len)
        {
            printf("%.*s\n", len, start);
            found = 1;
        }
        else if (cmpstr(start, w, len) != 0)
        {
            printf("%.*s\n", len, start);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Нет слов, отличных от '%s'\n", w);
    }
}
