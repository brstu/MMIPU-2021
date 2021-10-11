                                      МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ
                                                УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ 
                                  «БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»
                                                    КАФЕДРА ИИТ








                                                Лабораторная работа №1
                                         Моделирование управляемого объекта











                                                                                Выполнил:
                                                                                студент 3 курса
                                                                                группы АС-55
                                                                                Сенкевич Р. Н.

                                                                                Проверил:
                                                                                Иванюк Д. С.









                                                  Брест, 2021  
```
Цель: Написать программу, которая имитирует температуру данного объекта.

Ход работы:

Код:
```
```
#include <iostream>
#include "cmath"
#include "math.h"
using namespace std;
int main()
{

    int i;
    float a = 1, b = 0.2, c = 0.03, d = 0.004;
    float firstModel, secondModel;
    float warm = 2.5;
    float time;
    cout << "enter the time in second more then 1:";
    cin >> time;
    cout << "enter room temperature in Joule:";
    cin >> firstModel;
    secondModel = firstModel;
    cout << 0 << "\ t" << firstModel << "\ t" << secondModel << endl;
    firstModel = a * firstModel + b * warm;
    secondModel = firstModel;
    for (i = 1; i < time; i++) {
        firstModel = a * firstModel + b * warm;
        secondModel = a * secondModel - b * pow(secondModel, 2) + c * warm + d * sin(warm);
        cout << "At the time of" << i << "second" << endl;
        cout << "The first model has a temperature of " << firstModel << " oC" << endl;
        cout << "The second model has a temperature of " << secondModel << " oC" << endl;
    }
    return 0;
}
```
