#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20

struct Matrix
{
    float array[MAX_SIZE][MAX_SIZE];
    int m, n;
};

int readMatrix(struct Matrix *a);
void printMatrix(struct Matrix a);
int addMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c);
int subMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c);
int mulMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c);
int minorMatrix(struct Matrix *a, int m, int n, struct Matrix *b);
int tranMatrix(struct Matrix *a, struct Matrix *b);
int detMatrix(struct Matrix *a, float *b);
int invMatrix(struct Matrix *a, struct Matrix *b);

int main()
{
    printf("Welcome to Matrix Calculator CLI APP! \n");
    printf("Which operation do you want? \n");
    printf("  1. Summation of two matrix \n");
    printf("  2. Subtraction of two matrix \n");
    printf("  3. Multiplication of two matrix \n");
    printf("  4. Transpose of a matrix \n");
    printf("  5. Determinant of a matrix \n");
    printf("  6. Inverse of a matrix \n");
    printf("  0. Exit \n");
    int operation = 0;
    scanf("%d", &operation);
    struct Matrix m1;
    struct Matrix m2;
    struct Matrix m3;
    float det = 0;
    switch (operation)
    {
    case 0:
        return 0;
    case 1:
        printf("How do you want to give me the first matrix? \n");
        if (!readMatrix(&m1))
        {
            break;
        }
        printf("How do you want to give me the second matrix? \n");
        if (!readMatrix(&m2))
        {
            break;
        }
        if (addMatrix(&m1, &m2, &m3))
        {
            printf("How do you want to receive the results? \n");
            printMatrix(m3);
        }
        break;
    case 2:
        printf("How do you want to give me the first matrix? \n");
        if (!readMatrix(&m1))
        {
            break;
        }
        printf("How do you want to give me the second matrix? \n");
        if (!readMatrix(&m2))
        {
            break;
        }
        if (subMatrix(&m1, &m2, &m3))
        {
            printf("How do you want to receive the results? \n");
            printMatrix(m3);
        }
        break;
    case 3:
        printf("How do you want to give me the first matrix? \n");
        if (!readMatrix(&m1))
        {
            break;
        }
        printf("How do you want to give me the second matrix? \n");
        if (!readMatrix(&m2))
        {
            break;
        }
        if (mulMatrix(&m1, &m2, &m3))
        {
            printf("How do you want to receive the results? \n");
            printMatrix(m3);
        }
        break;
    case 4:
        printf("How do you want to give me the matrix? \n");
        if (!readMatrix(&m1))
        {
            break;
        }
        if (tranMatrix(&m1, &m2))
        {
            printf("How do you want to receive the results? \n");
            printMatrix(m2);
        }
        break;
    case 5:
        printf("How do you want to give me the matrix? \n");
        if (!readMatrix(&m1))
        {
            break;
        }
        if (detMatrix(&m1, &det))
        {
            printf("%f\n", det);
        }
        break;
    case 6:
        printf("How do you want to give me the matrix? \n");
        if (!readMatrix(&m1))
        {
            break;
        }
        if (invMatrix(&m1, &m2))
        {
            printf("How do you want to receive the results? \n");
            printMatrix(m2);
        }
        break;
    default:
        break;
    }
    main();
    return 0;
}

int readMatrix(struct Matrix *a)
{
    int inputType = 0;
    printf("  1. Standard input \n");
    printf("  2. File \n");
    scanf("%d", &inputType);
    printf("Enter the dimensions of the matrix: \n");
    scanf("%d %d", &(*a).m, &(*a).n);
    if (((*a).m < 2 && (*a).n < 2))
    {
        printf("Not acceptable dimensions! \n");
        return 0;
    }
    if ((*a).m > MAX_SIZE || (*a).n > MAX_SIZE)
    {
        printf("Not acceptable dimensions! (too large) \n");
        return 0;
    }
    if (inputType == 1)
    {
        printf("Enter the contents of the matrix: \n");
        for (int i = 0; i < (*a).m; i++)
        {
            for (int j = 0; j < (*a).n; j++)
            {
                scanf("%f", &(*a).array[i][j]);
            }
        }
    }
    else
    {
        printf("Enter the address of output file: \n");
        char addr[100];
        scanf("%s", addr);
        FILE *fp;
        fp = fopen(addr, "r");
        for (int i = 0; i < (*a).m; i++)
        {
            for (int j = 0; j < (*a).n; j++)
            {
                fscanf(fp, "%f", &(*a).array[i][j]);
            }
        }
    }
    return 1;
};

void printMatrix(struct Matrix a)
{
    int inputType = 0;
    printf("  1. Standard input \n");
    printf("  2. File \n");
    scanf("%d", &inputType);
    if (inputType == 1)
    {
        for (int i = 0; i < a.m; i++)
        {
            for (int j = 0; j < a.n; j++)
            {
                printf("%f ", a.array[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Enter the address of output file: \n");
        char addr[100];
        scanf("%s", addr);
        FILE *fp;
        fp = fopen(addr, "w");
        for (int i = 0; i < a.m; i++)
        {
            for (int j = 0; j < a.n; j++)
            {
                fprintf(fp, "%f ", a.array[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    }
};

int addMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c)
{
    if ((*a).m != (*b).m || (*a).n != (*b).n)
    {
        printf("Not possible. Dimensions of matrices must be equal! \n");
        return 0;
    }
    (*c).m = (*a).m;
    (*c).n = (*a).n;
    for (int i = 0; i < (*a).m; i++)
    {
        for (int j = 0; j < (*a).n; j++)
        {
            (*c).array[i][j] = (*a).array[i][j] + (*b).array[i][j];
        }
    }
    return 1;
};

int subMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c)
{
    if ((*a).m != (*b).m || (*a).n != (*b).n)
    {
        printf("Not possible. Dimensions of matrices must be equal! \n");
        return 0;
    }
    (*c).m = (*a).m;
    (*c).n = (*a).n;
    for (int i = 0; i < (*a).m; i++)
    {
        for (int j = 0; j < (*a).n; j++)
        {
            (*c).array[i][j] = (*a).array[i][j] - (*b).array[i][j];
        }
    }
    return 1;
};

int mulMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *c)
{
    if ((*a).n != (*b).m)
    {
        printf("Not possible. Number of columns in first matrix must be equal to number of rows in second matrix! \n");
        return 0;
    }
    (*c).m = (*a).m;
    (*c).n = (*b).n;
    for (int i = 0; i < (*c).m; i++)
    {
        for (int j = 0; j < (*c).n; j++)
        {
            (*c).array[i][j] = 0;
            for (int k = 0; k < (*a).n; k++)
            {
                (*c).array[i][j] += (*a).array[i][k] * (*b).array[k][j];
            }
        }
    }
    return 1;
};

int tranMatrix(struct Matrix *a, struct Matrix *b)
{
    (*b).m = (*a).n;
    (*b).n = (*a).m;
    for (int i = 0; i < (*b).m; i++)
    {
        for (int j = 0; j < (*b).n; j++)
        {
            (*b).array[i][j] = (*b).array[j][i];
        }
    }
    return 1;
};

int minorMatrix(struct Matrix *a, int m, int n, struct Matrix *b)
{
    if ((*a).m >= m && (*a).n >= n)
    {
        (*b).m = (*a).m - 1;
        (*b).n = (*a).n - 1;
        for (int i = 0; i < (*b).m; i++)
        {
            for (int j = 0; j < (*b).n; j++)
            {
                if (i < m - 1 && j < n - 1)
                {
                    (*b).array[i][j] = (*a).array[i][j];
                }
                else if (i < m - 1 && j >= n - 1)
                {
                    (*b).array[i][j] = (*a).array[i][j + 1];
                }
                else if (i >= m - 1 && j < n - 1)
                {
                    (*b).array[i][j] = (*a).array[i + 1][j];
                }
                else
                {
                    (*b).array[i][j] = (*a).array[i + 1][j + 1];
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
};

int detMatrix(struct Matrix *a, float *b)
{
    if ((*a).m != (*a).n)
    {
        printf("Not possible. Number of columns must be equal to number of rows! \n");
        return 0;
    }
    *b = 0;
    float det = 0;
    struct Matrix minor;
    if ((*a).m > 2)
    {
        for (int i = 0; i < (*a).m; i++)
        {
            minorMatrix(a, i + 1, 1, &minor);
            detMatrix(&minor, &det);
            *b += pow(-1, i) * (*a).array[i][0] * det;
        }
    }
    else
    {
        *b = (*a).array[0][0] * (*a).array[1][1] - (*a).array[0][1] * (*a).array[1][0];
    }
    return 1;
};

int invMatrix(struct Matrix *a, struct Matrix *b)
{
    if ((*a).m != (*a).n)
    {
        printf("Not possible. Number of columns must be equal to number of rows! \n");
        return 0;
    }
    float det = 0;
    detMatrix(a, &det);
    if (det == 0)
    {
        printf("Does not exist. Determinant of matrix is zero! \n");
        return 0;
    }
    (*b).m = (*a).m;
    (*b).n = (*a).n;
    float detMinor = 0;
    struct Matrix minor;
    if ((*b).m > 2)
    {
        for (int i = 0; i < (*b).m; i++)
        {
            for (int j = 0; j < (*b).n; j++)
            {
                minorMatrix(a, i + 1, j + 1, &minor);
                detMatrix(&minor, &detMinor);
                (*b).array[j][i] = (pow(-1, i + j) * detMinor) / det;
            }
        }
    }
    else
    {
        (*b).array[0][0] = ((*a).array[1][1]) / det;
        (*b).array[0][1] = -((*a).array[0][1]) / det;
        (*b).array[1][0] = -((*a).array[1][0]) / det;
        (*b).array[1][1] = ((*a).array[0][0]) / det;
    }
    return 1;
};