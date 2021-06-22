#include <stdio.h>
#include <string.h>
#include <ctype.h>

void change(char *, int);
int check(char *);
void capitalize(char *, char *);

int main()
{
  char s[100];
  int i = 0, d;
  // getting string from user
  while ((d = getchar()) != '\n')
  {
    s[i] = d;
    i++;
  }
  s[i] = 0;
  // getting n from user
  int n;
  scanf("%d", &n);
  // calling change function
  change(s, n);
  // printing the result
  printf("%s\n", s);
}

void change(char *s, int n)
{
  char *start;
  char *end;
  start = s;
  end = s;
  int l = 0;
  while (*end != '\0')
  {
    if (check(end))
    {
      end++;
    }
    else
    {
      l = (end - start) / sizeof(char);
      if (l == n)
      {
        capitalize(start, end);
      }
      start = end + 1;
      end = end + 1;
    }
  }
  l = (end - start) / sizeof(char);
  if (l == n)
  {
    capitalize(start, end);
  }
}

int check(char *end)
{
  if (('A' <= *end) && (*end <= 'z'))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void capitalize(char *start, char *end)
{
  while (start != end)
  {
    *start = toupper(*start);
    start++;
  }
}
