# <p align="center"> Министерство образования Республики Беларусь </p>
## <p align="center"> Учреждение образования «Брестский государственный технический университет»</p>
### <p align="center"> Кафедра ИИТ</p>

#### <p align="center">Лабораторная работа №1</p>
#### <p align="center">Modeling controlled object (Моделирование управляемого объекта)</p>

<p align="right" >Выполнил: </p>
<p align="right" >Студент 3 курса</p>
<p align="right" >Группы АС-55</p>
<p align="right" >Мартынович С.В.</p>
<p align="right" >Проверил:</p>
<p align="right" >Иванюк Д.С.</p>

#### <p align="center">Брест, 2021</p>

<p align="center">Цель работы: Написать программу, которая имитирует температуру данного объекта.</p>

<p align="center">Ход работы </p>
Код программы:


``` 


#include <iostream>

using namespace std;

int main() {
	const double a = 0.5, b = 0.05, c = 0.04, d = 0.004;
	int moments;
	double u_t, y_t, y2_t;
	cout << "Input max count of discrete moments: ";
	cin >> moments;
	if (moments < 1) {
		cout << "Error!";
		return 0;
	}  
	cout << "Enter temperature (y(t)): ";
	cin >> y_t;
	cout << "Enter input warm (u(t)): ";
	cin >> u_t;
	
	y2_t = y_t;
	cout << "Linear model:\t" << "Nonlinear model:" << endl;
	for (int i = 0; i < moments; i++) {
		y_t = a * y_t + b * u_t;
		y2_t = a * y2_t - b * pow(y2_t, 2) + c * u_t + d * sin(u_t);
		cout << i + 1 << ") " << y_t << "\t\t" << i + 1 << ") " << y2_t <<  endl;
	}
  }
