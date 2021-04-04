#include <stdio.h>

#define MAX_SIZE 100

int norm_1_inf(int A[][MAX_SIZE], int m, int n);

int main()
{
  int m, n;
  int A[MAX_SIZE][MAX_SIZE];

  // read the matrix
  // store in upper-left m by n block of A
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &A[i][j]);

  // print the L_1_infinity norm of A
  printf("%d\n", norm_1_inf(A, m, n));
}

int norm_1_inf(int A[][MAX_SIZE], int m, int n)
{
  // compute the L_1_infinity norm of a matrix
  int array[n];
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
      if (A[j][i] > 0)
      {
        sum = sum + A[j][i];
      }
      else
      {
        sum = sum - A[j][i];
      }
    }
    array[i] = sum;
  }
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  return max;
}
