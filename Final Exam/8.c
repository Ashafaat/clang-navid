#include <stdio.h>

#define MAX_SIZE 1000

struct List
{
  int size;
  int buffer[MAX_SIZE];
};

struct List readList();
struct List concatLists(struct List l1, struct List l2);
void printList(struct List list);

int main()
{
  struct List list1, list2, list3;

  list1 = readList();
  list2 = readList();

  list3 = concatLists(list1, list2);

  printList(list3);

  return 0;
}

struct List readList()
{
  struct List l;
  scanf("%d", &l.size);
  for (int i = 0; i < l.size; i++)
  {
    scanf("%d", &l.buffer[i]);
  }
  return l;
}

struct List concatLists(struct List l1, struct List l2)
{
  struct List l;
  l.size = l1.size + l2.size;
  for (int i = 0; i < l1.size; i++)
  {
    l.buffer[i] = l1.buffer[i];
  }
  for (int i = l1.size; i < l.size; i++)
  {
    l.buffer[i] = l2.buffer[i - l1.size];
  }
  return l;
}

void printList(struct List list)
{
  for (int i = 0; i < list.size; i++)
  {
    printf("%d ", list.buffer[i]);
  }
}
