<div style="text-align:center">МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ</br>
УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ</br>
«БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»</br>
КАФЕДРА ИИТ</br>
</div>


<div style="text-align:center"><b>Лабораторная работа №1</br>
Моделирование управляемого объекта</div></br></br></br>

<div style="text-align: right"> Выполнил:</br>
студент 3 курса</br>
группы АС-55</br>
Лепешев В. И.</br></br>
Проверил:</br>
Иванюк Д. С. </div>


<div style="text-align:center">Брест, 2021</div></br></br>	
<p style="margin-left:4%"><b><i>Цель:</i></b> Написать программу, которая имитирует температуру данного объекта.</p>

<div style="text-align:center; font-style: italic; font-weight: bold">Ход работы:</div>

```
#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;

int main() {
long t = 0, n = 1;
double f_t = 0;
const double a = 0.9, b = 0.001, c = 1, d = 0.123;
cout << "Enter the time in seconds more than 1" << endl;
cin >> n;
if (n <= 1) {
	cout << "Incorrect time" << endl;
	exit(0);
}
double* y1_t = new double[n + 1]{ 0 };
double* y2_t = new double[n + 1]{ 0 };
cout << "Enter input warm in Joule" << endl;
cin >> f_t;
cout << "Enter room temperature in Celsius" << endl;
cin >> y1_t[0];
y2_t[0] = y1_t[0];
system("cls");
cout << "Time: " << t + 1 << " seconds" << endl;
y1_t[t + 1] = a * y1_t[t] + b * f_t;
y2_t[t + 1] = a * y2_t[t] - b * pow(y2_t[0], 2) + c * f_t + d * sin(f_t);
cout << "First object temperature:" << endl << y1_t[t] << " oC" << endl;
cout << "Second object temperature:" << endl << y2_t[t] << " oC" << endl;
for (t = 1; t < n; t++) {
	y1_t[t + 1] = a * y1_t[t] + b * f_t;
	y2_t[t + 1] = a * y2_t[t] - b * pow(y2_t[t - 1], 2) + c * f_t + d * sin(f_t);
	Sleep(330);
	system("cls");
	cout << "Time: " << t + 1 << " seconds" << endl;
	cout << "First object temperature:" << endl << y1_t[t] << " oC" << endl;
	cout << "Second object temperature:" << endl << y2_t[t] << " oC" << endl;
}
delete[] y1_t;
delete[] y2_t;
}
```
<p style="margin-left:4%"><b><i>Вывод:</i></b> написал программу, которая имитирует температуру объекта.</p>

 

