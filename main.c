#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_NUM_LEN 1000
bool IsMultiple(const char *text, size_t buf_size, int divisor) {

    if (text == NULL || buf_size == 0 || divisor == 0)
    {
        return false;
    }

    if (divisor < 0) divisor = -divisor;

    size_t i = 0;

    if (text[0] == '-')
    {
        i = 1;
    }


    if (i >= buf_size || text[i] == '\0')
        return false;

    long long remainder = 0;

    for (; i < buf_size && text[i] != '\0'; i++)
    {
        if (text[i] < '0' || text[i] > '9')
            return false;

        int digit = text[i] - '0';

        if (remainder > (LLONG_MAX - digit) / 10)
            return false;

        remainder = (remainder * 10 + digit) % divisor;
    }

    return (remainder == 0);
}

int main()
{
    char num[MAX_NUM_LEN] = "1234ы56748";
    int divisor = 4;

    if (IsMultiple(num, sizeof(num), divisor))
        printf("Success: Multiple of %d\n", divisor);
    else
        printf("Failure: Not a multiple or invalid data\n");
    return 0;
}
