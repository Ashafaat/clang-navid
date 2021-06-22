#include <stdio.h>

void rotate_array(int array[], int size, int nr);
void print_array(int array[], int size);

int main()
{
  int size;
  int array[1000];
  int nr;

  // receiving the input array
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
    scanf("%d", &array[i]);
  scanf("%d", &nr);

  // print the array before the rotation
  print_array(array, size);

  // rotate array
  rotate_array(array, size, nr);

  // print the array after the rotation
  print_array(array, size);

  return 0;
}

void print_array(int array[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d, ", array[i]);
  putchar('\n');
}

void rotate_array(int array[], int size, int nr)
{
  // rotate the array nr times to the left
  for (int i = 1; i < nr + 1; i++)
  {
    int temp = 0;
    temp = array[0];
    for (int j = 0; j < size - 1; j++)
    {
      array[j] = array[j + 1];
    }
    array[size - 1] = temp;
  }
}
