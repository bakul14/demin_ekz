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
    int box = 10; // эта переменная хранит объем пространства, в которое будут помещаться сортируемые числа
    int *pArray = (int *)malloc(box * sizeof(int)); // создаем указатель на массив данных размером "box" элементов типа int
    int number = 0; // сюда будет попадать каждое новое число из консоли
    int counter = 0; // счетчик количества элементов

    while (scanf("%d", &number)) // вводим через побел сколь угодно много чисел, дальше ctrl+d, затем enter
    {
        pArray[counter] = number; //записываем в массив число из консоли
        counter++; // инкрементируем счетчик
        if (counter >= box) // если кол-во элементов > размера коробки:
        {
            box *= 2; // удваиваем переменную, которая хранит в себе объем хранилища
            pArray = (int *)realloc(pArray, box * sizeof(int)); // расширяем память до новой box
        }
    }

    quick_sort(pArray, 0, counter); // вызов сортировки

    for (int i = 0; i < counter; i++) // выводим результат
        printf("%d ", *(pArray + i), counter);

    return 0;
}