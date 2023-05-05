#include <stdio.h>
int main()
{
    int swap;
    int a[] = { 6,7,8,9 };
    int b[] = { 1,2,3,4 };
    int c[8];

    for (int i = 0; i < 4; i++)
    {
        c[i] = a[i];
    }

    for (int i = 4; i < 8; i++)
    {
        c[i] = b[i - 4];
    }

    printf("A Dizesi: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", a[i]);
    }

    printf("-B Dizesi: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nBirlestirilmis Dize: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\nSiralama Yapiliyor!");
    printf("\nSiralama Yapildi: ");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7 - i; j++)
        {
            if (c[j] > c[j + 1])
            {
                swap = c[j];
                c[j] = c[j + 1];
                c[j + 1] = swap;

            }
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
