#include <iostream>
#include "cmath"
#include "math.h"
using namespace std;
int main()
{

	setlocale(LC_ALL, "Russian");
	int i;
	float a = 2, b = 0.24, c = 0.132, d = 0.1836;
	float x0 = 1.5, x1, x2, x;
	float u_t = 2.5;
	float ut_1 = 3.5;
	float t;
	cout << "Максимальное значение дискретных моментов, не меньше 1:";
	cin >> t;
	cout << "Введите входную температуру объекта:";
	cin >> x1;
	x2 = x1;
	cout << "Линельная модель   Нелинейная модель" << endl;
	cout << 0 << "\ t" << x1 << "\ t" << x2 << endl;
	x1 = a * x1 + b * u_t;
	x = x1;
	for (i = 1; i < t; i++) {
		x1 = a * x1 + b * u_t;
		x2 = a * x2 - b * pow(x, 2) + c * u_t + d * sin(ut_1);
		cout << i << "\ t" << x1 << "\ t" << x2 << endl;
	}
	return 0;
}