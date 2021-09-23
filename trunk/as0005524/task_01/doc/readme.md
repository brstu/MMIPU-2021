Министерство образования Республики Беларусь

Учреждение образования

Брестский Государственный технический университет

Кафедра ИИТ

**Лабораторная работа №1**

**«Моделирование управляемого объекта»**

Выполнил:

Студент 3 курса

Группы АС-55

Сенкевич Р. Н.

Проверил:

Иванюк Д.С.

Брест, 2021

**Цель работы:** Написать программу, которая имитирует температуру
данного объекта.

**Ход работы**

\#include <iostream>

\#include <cmath>

**using** **namespace** std;

**int** main() {

**int** time;

**float** warm;

**const** **float** a = 1, b = 0.2, c = 0.03, d = 0.004;

**float**\* firstModel = **new** **float**[]{};

**float**\* secondModel = **new** **float**[]{};

cout << "Enter the time in second" << endl;

cin >> time;

**if** (time &lt;= 1) {

cout << "Incorrect value. The time value must be greater than 1"
<< endl;

**return** 0;

}

cout << "Enter warm in Joule (good value is 100)" << endl;

cin >> warm;

cout << "Enter room temperature in Celsius (good value is 12)"
<< endl;

cin >> firstModel\[0\];

secondModel\[0\] = firstModel\[0\];

**for** (**int** i = 0; i < time; i++) {

firstModel\[i + 1\] = a \* firstModel\[i\] + b \* warm;

secondModel\[i + 1\] = a \* secondModel\[i\] - b \* pow(secondModel\[i -
1\], 2)

+ c \* warm + d \* sin(warm);

cout << endl;

cout << "At the time оf " << i << " second" <<
endl;

cout << "The first model has a temperature of " <<
firstModel\[i\] << " oC" << endl;

cout << "The second model has a temperature of " <<
secondModel\[i\] << " oC" << endl;

}

cout << endl;

**delete**\[\] firstModel;

**delete**\[\] secondModel;

**return** 0;

}

**Вывод:** написал программу, которая имитирует температуру данного
объекта.
