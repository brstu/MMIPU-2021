# <p align="center"> Министерство образования Республики Беларусь </p>
## <p align="center"> Учреждение образования «Брестский государственный технический университет»</p>
### <p align="center"> Кафедра ИИТ</p>










#### <p align="center">Лабораторная работа №1</p>
#### <p align="center">Modeling controlled object (Моделирование управляемого объекта)</p>









<p align="right" >Выполнил: </p>
<p align="right" >Студент 3 курса</p>
<p align="right" >Группы АС-55</p>
<p align="right" >Тарасевич А.A.</p>
<p align="right" >Проверил:</p>
<p align="right" >Иванюк Д.С.</p>








#### <p align="center">Брест, 2021</p>









<p align="center">Цель работы: Написать программу, которая имитирует температуру данного объекта.</p>

<p align="center">Ход работы </p>  

```
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a = 0.5;
	double b = 0.005;
	double c = 0.055;
	double d = 0.0005;
	double y0 = 20;
	double y1, y2, y;
	double ut = 5, ut1 = 3;
	int t;
	cout << "Input max count of discrete moment not less than l: ";
	cin >> t;
	if (t > 0)
	{

		cout << "Input temperature of some object: ";
		cin >> y1;
		y2 = y1;
		cout << "\tLinear model\t\t\t\t\t\t\Nonlinear model" << endl;
		cout << 0 << "\t\t" << y1 << "\t\t\t\t\t\t" << y2 << endl;
		y1 = a * y1 + b * ut;
		y = y1;
		for (int i = 1; i <= t; i++) {
			y1 = a * y1 + b * ut;
			y2 = a * y2 - b * pow(y, 2) + c * ut + d * sin(ut1);
			cout << i << "\t\t" << y1 << "\t\t\t\t\t\t" << y2 << endl;
		}

	}
	else
	{
		cout << "invalid count " << endl;
	}

	return 0;

}
```                     
