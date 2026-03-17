// 2. В заданный непустой текст входят только цифры и буквы. Определить, является ли текст десятичной записью числа, кратного 4.
//Tests:
// text = "12345648" output: multiple of 4
// text = "12345649" output: not multiple of 4
// text = "" output: string is empty
// text = "123a" output: not in decimal system
#include <stdio.h>
#include <string.h>
#define MAX_TEXT_LEN 1000
int main()
{
    char text[MAX_TEXT_LEN] = "12345648";
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
      printf("string is empty");
}
