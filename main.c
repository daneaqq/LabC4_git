// 3. Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, пробел,
// за последним словом – точка. Напечатать все слова из списка, отличные от заданного слова W.
//Tests:
// input: "abc, bca, bac.", w: "bca" output: abc bac
// input: "abc,  bca  ,  bac  .", w: "bca" output: abc bac
// input: "abc,,,bca,,,bac.", w: "bca" output: abc bac
// input: "abc.", w: "abc" output: there are no other words
// input: "abc.", w: "xyz" output: abc
// input: "abc,bca.", w: "" output: abc bca
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LEN 1000
#define MAX_W_LEN 100

int cmpstr(const char *word_start, size_t word_len, const char *w, size_t w_buf_size)
{
    if (word_start == NULL || w == NULL || word_len == 0 || w_buf_size == 0)
      return -1;

    size_t w_len = 0;
    while (w_len < w_buf_size && w[w_len] != '\0')
        w_len++;

    if (word_len != w_len)
      return -2;

    for (size_t i = 0; i < word_len; i++)
        if (word_start[i] != w[i])
          return -2;

    return 0;
}

void process_w(const char *input, size_t in_buf_size, const char *w, size_t w_buf_size)
{
    if (input == NULL || w == NULL || in_buf_size == 0 || w_buf_size == 0)
        return;

    const char *p = input;
    const char *end = input + in_buf_size;
    bool found_any = false;

    while (p < end && *p != '\0' && *p != '.')
    {
        while (p < end && (*p == ' ' || *p == ',') && *p != '\0' && *p != '.')
            p++;

        if (p >= end || *p == '\0' || *p == '.')
          break;

        const char *word_start = p;
        while (p < end && *p != ' ' && *p != ',' && *p != '.' && *p != '\0')
            p++;

        size_t word_len = (size_t)(p - word_start);

        if (word_len > 0)
        {
            if (cmpstr(word_start, word_len, w, w_buf_size))
            {
                printf("%.*s\n", (int)word_len, word_start);
                found_any = true;
            }
        }
    }

    if (!found_any)
        printf("there are no other words\n");
}

int main()
{
    char input[MAX_INPUT_LEN] = "abc.";
    char w[MAX_W_LEN] = "xyz";

    process_w(input, sizeof(input), w, sizeof(w));

    return 0;
}
