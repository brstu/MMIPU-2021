# <p align="center"> Министерство образования Республики Беларусь </p>
## <p align="center"> Учреждение образования «Брестский государственный технический университет»</p>
### <p align="center"> Кафедра ИИТ</p>










#### <p align="center">Лабораторная работа №1</p>
#### <p align="center">Modeling controlled object (Моделирование управляемого объекта)</p>









<p align="right" >Выполнил: </p>
<p align="right" >Студент 3 курса</p>
<p align="right" >Группы АС-55</p>
<p align="right" >Куликовский А.М.</p>
<p align="right" >Проверил:</p>
<p align="right" >Иванюк Д.С.</p>








#### <p align="center">Брест, 2021</p>









<p align="center">Цель работы: Написать программу, которая имитирует температуру данного объекта.</p>

<p align="center">Ход работы </p>

Код программы :
```


#include <iostream>
#include "cmath"
using namespace std;
void LineModel(float a, float b, float y1, float y2);
void NonLineModel(float a, float b, float c, float d, float y1, float y2);

int main()
{
	LineModel(1, 0.0011, 0.52, 4);
	NonLineModel(1, 0.0011, 0.52, 4, 5, 6);
	return 0;
}

void LineModel(float a, float b, float y1, float y2)
{
	cout << "\t\t LineModel" << endl;
	float yt;
	for (int i = 0; i <= 10; ++i)
	{
		yt = a * y2 + b * y1;
		y2 = yt;
		cout << "y(t" << i << ") = " << y2 << " || " << " y(t+1) = " << yt << endl;
	}
}

void NonLineModel(float a, float b, float c, float d, float y1, float y2)
{
	cout << "----------------------------" << endl;
	cout << "\t\t NonLineModel" << endl;
	float yt_1 = 0;
	float yt_2;
	for (int i = 0; i <= 10; ++i)
	{
		yt_2 = a * y2 - b * yt_1 * yt_1 + c * y1 + d * sin(y1);
		yt_1 = y2;
		y2 = yt_2;
		cout << "y(t" << i << ")" << " = " << y2 << " || " << "y(t+1) = " << yt_2 << endl;
	}
}
