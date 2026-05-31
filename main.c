// 3. Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, пробел,
// за последним словом – точка. Напечатать все слова из списка, отличные от заданного слова W.

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

const char* get_next_word(const char *current, size_t *word_len)
{
    if (current == NULL || word_len == NULL)
        return NULL;

    while (*current == ' ' || *current == ',')
        current++;

    if (*current == '\0' || *current == '.')
        return NULL;

    const char *start = current;

    while (*current != ' ' && *current != ',' && *current != '.' && *current != '\0')
        current++;

    *word_len = (size_t)(current - start);

    return start;
}

int main()
{
    char input[MAX_INPUT_LEN] = "abc, bca, bac.";
    char w[MAX_W_LEN] = "bca";
    // char input[MAX_INPUT_LEN] = "abc.";
    // char w[MAX_W_LEN] = "xyz";
    // char input[MAX_INPUT_LEN] = "abc,bca.";
    // char w[MAX_W_LEN] = "";
    // char input[MAX_INPUT_LEN] = "hello, world.";
    // char w[MAX_W_LEN] = "test";
    // char input[MAX_INPUT_LEN] = "abc, bca , bac .";
    // char w[MAX_W_LEN] = "bca";
    // char input[MAX_INPUT_LEN] = "abc,,,bca,,,bac.";
    // char w[MAX_W_LEN] = "bca";
    // char input[MAX_INPUT_LEN] = "abc,bca..";
    // char w[MAX_W_LEN] = "bca";
    // char input[MAX_INPUT_LEN] = "abc.";
    // char w[MAX_W_LEN] = "abc";
    // char input[MAX_INPUT_LEN] = "bca, bca, bca.";
    // char w[MAX_W_LEN] = "bca";
    // char input[MAX_INPUT_LEN] = ".";
    // char w[MAX_W_LEN] = "w";
    // char input[MAX_INPUT_LEN] = "";
    // char w[MAX_W_LEN] = "xyz";
    // char input[MAX_INPUT_LEN] = "abc, bca";
    // char w[MAX_W_LEN] = "bca";

    const char *p = input;
    const char *word_start;
    size_t word_len;
    bool found_any = false;

    while ((word_start = get_next_word(p, NULL)) != NULL)
    {
        if (cmpstr(word_start, word_len, w, sizeof(w)) != 0)
        {
            printf("%.*s\n", (int)word_len, word_start);
            found_any = true;
        }

        p = word_start + word_len;
    }

    if (!found_any)
        printf("there are no other words\n");

    return 0;
}
