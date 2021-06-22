#include <stdio.h>
#include <math.h>

int check(int a, int b, int c)
{
    double q1 = b / a;
    double q2 = c / b;
    if (q1 == q2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    for (int i = 3; i < n + 1; i++)
    {
        if (check(a, b, c))
        {
            a = b;
            b = c;
            scanf("%d", &c);
        }
        else
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}