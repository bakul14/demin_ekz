/*  Программа quicksort.c:
------------------------------------------------------------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int i, int j) 
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void quick_sort(int *v, int left, int right)
{
    int i, mid;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    mid = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++mid, i);
    swap(v, left, mid);
    quick_sort(v, left, mid - 1);
    quick_sort(v, mid + 1, right);
}

int main()
{
    int number = 0;     // Сюда будет попадать каждое новое число из консоли
    int box = 0;       // Эта переменная хранит объем пространства, в которое будут помещаться сортируемые числа
    scanf("%d", &box);
    int *pArray = (int *)malloc(box * sizeof(int)); // Создаем указатель на массив данных размером "box" элементов типа int

    for (int i = 0; i < box; i++) {
        scanf("%d", &number);    
        pArray[i] = number;   // Записываем в массив число из консоли
    }

    quick_sort(pArray, 0, box-1);     // Вызов сортировки

    for (int j = 0; j < box; j++)   // Выводим результат
        printf("%d\n", *(pArray + j));

    return 0;
}