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