// 2. В заданный непустой текст входят только цифры и буквы. Определить, является ли текст десятичной записью числа, кратного 4.
#include <stdio.h>
#include <string.h>
int main()
{
    char text[1000] = "12345648";
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (text[i] < '0' || text[i] > '9')
        {
            printf("number is not in decimal system\n");
            return 0;
        }
    }
}
