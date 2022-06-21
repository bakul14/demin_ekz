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
    int box = 10; // ��� ���������� ������ ����� ������������, � ������� ����� ���������� ����������� �����
    int *pArray = (int *)malloc(box * sizeof(int)); // ������� ��������� �� ������ ������ �������� "box" ��������� ���� int
    int number = 0; // ���� ����� �������� ������ ����� ����� �� �������
    int counter = 0; // ������� ���������� ���������

    while (scanf("%d", &number)) // ������ ����� ����� ����� ������ ����� �����, ������ ctrl+d, ����� enter
    {
        pArray[counter] = number; //���������� � ������ ����� �� �������
        counter++; // �������������� �������
        if (counter >= box) // ���� ���-�� ��������� > ������� �������:
        {
            box *= 2; // ��������� ����������, ������� ������ � ���� ����� ���������
            pArray = (int *)realloc(pArray, box * sizeof(int)); // ��������� ������ �� ����� box
        }
    }

    quick_sort(pArray, 0, counter); // ����� ����������

    for (int i = 0; i < counter; i++) // ������� ���������
        printf("%d ", *(pArray + i), counter);

    return 0;
}