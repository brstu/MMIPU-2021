                                      МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ
                                                УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ 
                                  «БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»
                                                    КАФЕДРА ИИТ








                                                Лабораторная работа №1
                                         Моделирование управляемого объекта











                                                                                Выполнил:
                                                                                студент 3 курса
                                                                                группы АС-55
                                                                                Кучко А.В.

                                                                                Проверил:
                                                                                Иванюк Д. С.









                                                  Брест, 2021  





                                                  
`Цель: Написать программу, которая имитирует температуру данного объекта.`

`Ход работы:`

`Код:`
```
#include <iostream>

#include <cmath>

using namespace std;

void Linear(double a, double b, double y1, double y2);

void Nonlinear(double a, double b, double c, double d, double y1, double y2);

int main()

{

Linear(2, 0.005, 5, 3);

Nonlinear(2, 0.005, 0.055, 0.0005, 5, 3);

return 0;

}

void Linear(double a, double b, double y1, double y2)

{

double yt;

int N_linear;

cout << "Input max count of discrete moment for LinearModel , not less than 1: ";

cin >> N_linear;

cout << "\t\t LinearModel" << endl;

for (int i = 0; i <= N_linear; ++i)

{

yt = a * y2 + b * y1;

y2 = yt;

cout << "y(t" << i << ") = " << y2 << endl;

}

}

void Nonlinear(double a, double b, double c, double d, double y1, double y2)

{

double yt_1 = 0;

double yt_2;

int N_Nonlinear;

cout << "Input max count of discrete moment for NonLinearModel , not less than 1: ";

cin >> N_Nonlinear;

cout << "\t\t Nonlinear" << endl;

for (int i = 0; i <= N_Nonlinear; ++i)

{

yt_2 = a * y2 - b * yt_1 * yt_1 + c * y1 + d * sin(y1);

yt_1 = y2;

y2 = yt_2;

cout << "y(t" << i << ")" << " = " << y2 << endl;

}

}
```
`Вывод: написал программу, которая имитирует температуру объекта.`