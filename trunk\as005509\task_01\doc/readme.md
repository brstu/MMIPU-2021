МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ
# УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ 
«БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»

КАФЕДРА ИИТ








**Лабораторная работа №1**

**Моделирование управляемого объекта**











Выполнил: 

`                    `студент 3 курса

`                    `группы АС-55

`                    `Лепешев В. И.



`                   `Проверил:

Иванюк Д. С.









Брест, 2021

***Цель:*** Написать программу, которая имитирует температуру данного объекта.


Ход работы:

#include <iostream>

#include <conio.h>

#include "windows.h"

using namespace std;

int main() {

`	`long t = 0, n = 1;

`	`double f\_t = 0;

`	`const double a = 0.9, b = 0.001, c = 1, d = 0.123;

`	`cout << "Enter the time in seconds more than 1" << endl;

`	`cin >> n;

`	`if (n <= 1) {

`		`cout << "Incorrect time" << endl;

`		`exit(0);

`	`}

`	`double\* y1\_t = new double[n + 1]{ 0 };

`	`double\* y2\_t = new double[n + 1]{ 0 };

`	`cout << "Enter input warm in Joule" << endl;

`	`cin >> f\_t;

`	`cout << "Enter room temperature in Celsius" << endl;

`	`cin >> y1\_t[0];

`	`y2\_t[0] = y1\_t[0];

`	`system("cls");

`	`cout << "Time: " << t + 1 << " seconds" << endl;

`	`y1\_t[t + 1] = a \* y1\_t[t] + b \* f\_t;

`	`y2\_t[t + 1] = a \* y2\_t[t] - b \* pow(y2\_t[0], 2) + c \* f\_t + d \* sin(f\_t);

`	`cout << "First object temperature:" << endl << y1\_t[t] << " oC" << endl;

`	`cout << "Second object temperature:" << endl << y2\_t[t] << " oC" << endl;

`	`for (t = 1; t < n; t++) {

`		`y1\_t[t + 1] = a \* y1\_t[t] + b \* f\_t;

`		`y2\_t[t + 1] = a \* y2\_t[t] - b \* pow(y2\_t[t - 1], 2) + c \* f\_t + d \* sin(f\_t);

`		`Sleep(330);

`		`system("cls");

`		`cout << "Time: " << t + 1 << " seconds" << endl;

`		`cout << "First object temperature:" << endl << y1\_t[t] << " oC" << endl;

`		`cout << "Second object temperature:" << endl << y2\_t[t] << " oC" << endl;

`	`}

`	`delete[] y1\_t;

`	`delete[] y2\_t;

}

***Вывод:*** написал программу, которая имитирует температуру объекта.

