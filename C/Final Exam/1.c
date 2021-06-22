#include <stdio.h>
#include <math.h>

int main()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    int n = 0;
    scanf("%d", &n);
    int x_max = 0;
    int y_max = 0;
    int d_max = 0;
    int x_min = 0;
    int y_min = 0;
    int d_min = 0;
    for (int i = 1; i < n + 1; i++)
    {
        int current_x = 0;
        int current_y = 0;
        int current_d = 0;
        scanf("%d %d", &current_x, &current_y);
        current_d = sqrt(pow(x - current_x, 2) + pow(y - current_y, 2));
        if (i == 1)
        {
            d_min = current_d;
            x_min = current_x;
            y_min = current_y;
            d_max = current_d;
            x_max = current_x;
            y_max = current_y;
        }
        if (current_d > d_max)
        {
            x_max = current_x;
            y_max = current_y;
        }
        if (current_d < d_min)
        {
            x_min = current_x;
            y_min = current_y;
        }
    }

    printf("%d %d %d %d\n", x_min, y_min, x_max, y_max);

    return 0;
}