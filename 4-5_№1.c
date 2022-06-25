/*  Программа detab.c:
------------------------------------------------------------------------------------------------------------------------------------
    Напишите программу detab, заменяющую символы табуляции во вводимом тексте
    нужным числом пробелов (до следующего "стопа" табуляции). 
    Предполагается, что "стопы" табуляции расставлены на фиксированном расстоянии
    друг от друга, скажем,  через n позиций. 

    Как лучше задавать n — в виде значения переменной или в виде именованной константы? 
        Ответ - в виде именованной константы #define, т.к. n не меняется в ходе выполнения программы,
        адрес n нам не нужен, а значит использование переменной не имеет смысла. 
------------------------------------------------------------------------------------------------------------------------------------
    В этом задании нужно понимать, что \t это НЕ несколько пробелов подряд, а команда для перехода позиции курсора к следующему столбцу.
    Поток вывода виртуально разделен на столбцы, ширина каждого столбца - один tab (эквивалентно 8 пробелам по умолчанию).
    Например:
    "a\tb" = "a       b".           'a' стоит на 1 позиции, дальше идет (8-1=7) условных пробелов, и только на 9 позиции стоит 'b' 
    "abcdefg\th" = "abcdefg h"      'g' стоит на 7 позицииЮ дальше идет (8-7=1) пробел, и на 9 позиции стоит символ 'h'

    Заметьте, что кол-во пробелов в двуз вышепривеленных случаях разное, это нужно будет объяснить Демину.
------------------------------------------------------------------------------------------------------------------------------------
    Для решения задачи считываем по одному символу и выводим его. Как только обнаружили '\t', считаем, сколько пробелов не хватает
    до следующего столбца, и выводим нужное кол-во пробелов. Дальше снова выводим символы, пока не встретим '\t'.
*/


#include <stdio.h>

#define tab 8   // Кол-во пробелов, эквивалентное одному \t.

int main()
{
    int symbol;     // Сюда записываем очередной прочитанный символ.
    int pos = 1;    // Позиция символа в строке. Первый символ новой строки стоит на 1-ой позиции.
    int space = 0;  // Переменная для количества пробелов, которые будут выведены вместо \t.

    while ((symbol = getchar()) != EOF) { // Читаем все символы из потока ввода.
        if (symbol == '\n') {   // Если пришел символ новой строки:
            pos = 1;            // Сбрасываем позицию символа (позиция 1).
            putchar(symbol);    // Выводим символ новой строки.
        }
        else if (symbol == '\t') {          // Если встретили символ табуляции: 
            space = tab - ((pos - 1) % tab); // Считаем, сколько пробелов не хватает до полного столбца табуляции, исходя из текущей позиции символа.
            for (space; space > 0; space--) {  // Выводим нужное кол-во пробелов:
                putchar(' ');
                pos++;                      // Инкрементируем текущую позицию.
            }
        }
        else {                  // Если символ не управляющий (не \t и \n), то просто выводим его:
            putchar(symbol);    // Выводим символ.
            pos++;              // Инкрементируем текущую позицию.
        }
    }

    return 0;
}