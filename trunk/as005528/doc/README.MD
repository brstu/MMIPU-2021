                                     МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ
                                                УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ 
                                  «БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»
                                                    КАФЕДРА ИИТ



                                                Лабораторная работа №1
                                         Моделирование управляемого объекта



                                                                                Выполнила:
                                                                                Студентка 3 курса
                                                                                Группы АС-55
                                                                                Хмарик Д.А.
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

void linear(float a, float b, float y_t, float u_t, int n) {
	cout << "\nLinear model: " << endl << endl;

	for (int i = 0; i <= n; i++) {
		y_t = a * y_t + b * u_t;
		cout << "y(" << i << ") = " << y_t << endl;
	}
}

void nonLinear(float a, float b, float c, float d, float y_t, float u_t, int n) {
	cout << "\nNonlinear model: " << endl << endl;

	float y_t2 = 0;
	float y_t3 = 0;

	for (int i = 0; i <= n; i++) {
		y_t3 = y_t;
		y_t = a * y_t - b * pow(y_t2, 2) + c * u_t + d * sin(u_t);
		y_t2 = y_t3;
		cout << "y(" << i << ") = " << y_t << endl;
	}
}

int main() {
	int n = 0;
	enter:
	cout << "Enter the number of iterations: ";
	cin >> n;

	if (n < 0 || n > 50) {
		goto enter;
	}
	else {
		linear(2, 0.001, 0.03, 0.004, n);
		nonLinear(2, 0.001, 0.002, 0.003, 0.03, 0.004, n);
	}
	return 0;
}
```
`Вывод: Написала программу, имитирующую температуру объекта.`
