#include <stdio.h>
#include <stdlib.h>

void combsort(int *array, size_t size)
{
    if (array && size)
    {
        size_t jump = size, i;
        int swapped = 1;
        while (jump > 1 || swapped)
        {
            if (jump > 1) jump /= 1.24733;
            swapped = 0;
            for (i = 0; i + jump < size; ++i)
                if (array[i + jump] > array[i])
                {
                    int tmp;
                    tmp = array[i];
                    array[i] = array[i + jump];
                    array[i + jump] = tmp;
                    swapped = 1;
                }
        }
    }
}

int main()
{


    int i, n;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i<n; i++) scanf("%d", &a[i]);

    printf("\n");
    combsort(a,n);

    for (i = 0; i<n; i++) printf("%d ", a[i]);

    return 1;
}

