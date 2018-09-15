#include <stdio.h>
#include <stdlib.h>

void shellSort(int *num, int size)
{
    int increment = 3;
    while (increment > 0)
    {
        for (int i = 0; i < size; i++)
    {
            int j = i;
            int temp = num[i];

            while ((j >= increment) && (num[j - increment] > temp))
            {
                num[j] = num[j - increment];
                j = j - increment;
            }
            num[j] = temp;
        }
    if (increment > 1)      // делим приращение на 2
      increment = increment / 2;
    else if (increment == 1)   // последний проход завершён,
      break;  // выходим из цикла
  }
}

int main()
{
    int i, n;
    scanf("%d", &n);
    int array[n];
    for (i = 0; i<n; i++) scanf("%d", &array[i]);

    printf("\n");
    shellSort(array,n);

    for (i = 0; i<n; i++) printf("%d ", array[i]);

    return 1;
}


