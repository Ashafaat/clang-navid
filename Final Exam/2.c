#include <stdio.h>
#include <math.h>

int main()
{
    int r = 0;
    int i = 0;
    scanf("%d %d", &r, &i);
    int p = 0;
    scanf("%d", &p);

    int real_a_power_j = r;
    int image_a_power_j = i;
    for (int j = 2; j < p + 1; j++)
    {
        int real_temp = 0;
        int image_temp = 0;
        real_temp = real_a_power_j * r - image_a_power_j * i;
        image_temp = real_a_power_j * i + image_a_power_j * r;
        real_a_power_j = real_temp;
        image_a_power_j = image_temp;
    }

    printf("%d %d\n", real_a_power_j, image_a_power_j);

    return 0;
}