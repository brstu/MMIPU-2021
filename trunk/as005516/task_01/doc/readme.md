# <p align="center"> Министерство образования Республики Беларусь </p>
## <p align="center"> Учреждение образования «Брестский государственный технический университет»</p>
### <p align="center"> Кафедра ИИТ</p>

#### <p align="center">Лабораторная работа №1</p>
#### <p align="center">Modeling controlled object (Моделирование управляемого объекта)</p>

<p align="right" >Выполнил: </p>
<p align="right" >Студент 3 курса</p>
<p align="right" >Группы АС-55</p>
<p align="right" >Петров В.И.</p>
<p align="right" >Проверил:</p>
<p align="right" >Иванюк Д.С.</p>

#### <p align="center">Брест, 2021</p>

<p align="center">Цель работы: Написать программу, которая имитирует температуру данного объекта.</p>

<p align="center">Ход работы </p>
Код программы:


``` 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	setlocale(LC_ALL, "Russian");
	int koli4estvoT;
	cout << "Вввести максимальное количество дискретных моментов времени: ";
	cin >> koli4estvoT;
	double x1 = 0.45;
	double x2 = 0.028;
	double x3 = 0.036;
	double x4 = 0.0075;
	double y1, y2, y;
	double ut = 6, utl = 2;
	if (koli4estvoT > 0)
	{

		cout << "Введите температуру на входе: ";
		cin >> y1;
		y2 = y1;
		cout << "\t Линейная модель\t\t\t\t Нелинейная модель" << endl;
		cout << 0 << "\t\t" << y1 << "\t\t\t\t" << y2 << endl;
		y1 = x1 * y1 + x2 * ut;
		y = y1;
		
	}
	else
	{
		cout << "Ошибка: Недопустимое значение. " << endl;
	}

	for (int i = 1; i <= koli4estvoT; i++) {
		y1 = x1 * y1 + x2 * ut;
		y2 = x1 * y2 - x2 * pow(y, 2) + x3 * ut + x4 * sin(utl);
		cout << i << "\t\t" << y1 << "\t\t\t\t" << y2 << endl;
	}

	return 0;

}
