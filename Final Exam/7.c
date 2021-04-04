#include <stdio.h>
#include <string.h>

int main()
{
  char s[100];
  gets(s);
  int array[strlen(s)];
  for (int i = 0; i < strlen(s); i++)
  {
    scanf("%d", &array[i]);
  }
  char result[strlen(s) + 1];
  for (int i = 0; i < strlen(s); i++)
  {
    result[array[i] - 1] = s[i];
  }
  result[strlen(s)] = '\0';
  printf("%s", result);
  return 0;
}