// 2. В заданный непустой текст входят только цифры и буквы. Определить, является ли текст десятичной записью числа, кратного 4.
#include <stdio.h>
#include <string.h>
int main()
{
    char text[1000] = "12345648";
    int len = strlen(text);
    if (len>0)
    {
      for (int i = 0; i < len; i++)
      {
          if (text[i] < '0' || text[i] > '9')
          {
              printf("number is not in decimal system\n");
              return 0;
          }
      }
      int lasttwo = 0;
      if (len >= 2)
      {
          lasttwo = (text[len - 2] - '0') * 10 + (text[len - 1] - '0');
      }
      else
      {
          lasttwo = text[len - 1] - '0';
      }
      if ((lasttwo & 3) == 0)
          printf("number in the decimal system is a multiple of 4\n");
      else
          printf("number in the decimal system is not a multiple of 4\n");
      }
      else
      printf("string ie empty");
}
