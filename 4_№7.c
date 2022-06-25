/*  Программа quicksort.c:
------------------------------------------------------------------------------------------------------------------------------------
    Реализовать алгоритм быстрой сортировки
------------------------------------------------------------------------------------------------------------------------------------
    Сама функция быстрой сортировки взята из лекций Верстова
------------------------------------------------------------------------------------------------------------------------------------
    Помимо сортировки, в программе реализовано динамическое выделение и расширение памяти
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
    int box = 10;       // Эта переменная хранит объем пространства, в которое будут помещаться сортируемые числа
    int *pArray = (int *)malloc(box * sizeof(int)); // Создаем указатель на массив данных размером "box" элементов типа int
    int number = 0;     // Сюда будет попадать каждое новое число из консоли
    int counter = 0;    // Счетчик количества элементов

    while (scanf("%d", &number))    /* Вводим через пробел сколь угодно много чисел. Цикл завершится, когда в консоль будет введено 
                                     сочетание клавиш CTRL+D и ENTER*/
    {
        pArray[counter] = number;   // Записываем в массив число из консоли
        counter++;                  // Инкрементируем счетчик
        if (counter >= box)         // Если кол-во элементов > размера хранилища:
        {
            box *= 2;               // Удваиваем переменную, которая хранит в себе объем хранилища
            pArray = (int *)realloc(pArray, box * sizeof(int)); // Расширяем память до новой box
        }
    }

    quick_sort(pArray, 0, counter);     // Вызов сортировки

    for (int i = 0; i < counter; i++)   // Выводим результат
        printf("%d ", *(pArray + i), counter);

    return 0;
}