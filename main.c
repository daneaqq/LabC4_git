// 3. Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, пробел,
// за последним словом – точка. Напечатать все слова из списка, отличные от заданного слова W.
#include <stdio.h>
#include <string.h>

int cmpstr(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0')
            break;
    }
    return 0;
}
