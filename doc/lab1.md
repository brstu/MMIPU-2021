                                          Министерство образования Республики Беларусь

                                                       Учреждение образования

                                           «Брестский государственный технический университет»

                                                         Кафедра ИИТ

                                                     Лабораторная работа № 1

                                                        По дисциплине «ММПиУ»

                                                 Моделирование объекта управления.



Выполнила:

Студенка. группы. АС-55

Зинькова Д.Г
Проверил:

Иванюк Д.C.

Брест 2021
  
  
## Задание:  
На языке C++ реализовать программу, моделирующую объект управления, использую модели. Использовать ООП, должно быть не менее трех классов (один из них абстрактный) и наследование.

В отчете (файл документации \*.chm, сгенерированный Doxygen) также привести графики изменения температуры объекта, пояснить полученные результаты.

### Код программы:
notLinearModel.cpp:
```c++
#include "stdafx.h"
#include "notlinear.h"
#include <iostream>
#include <math.h>

using namespace std;

void notlinear::ShowResults() {
	cout << "Нелинейная модель " << endl << endl;
	cout.width(8);
	cout << " y" << " |  " << "u" << "  | " << "t" << endl << endl;
	y[0] = 0;
	y[1] = 0;
	for (int t = 1; t <= 10; t++) {
		if (t > 1){
		y[t] = 0.9*y[t-1] - 0.001*y[t - 2] * y[t - 2] + u + sin(u);
		}
	}
	for (int t = 1; t <= 10; t++) {
		cout.width(8);
		cout << y[t] << " | " << u << " | " << t << endl;
	}
}


```
linearModel.cpp:
```c++
#include "stdafx.h"
#include "linear.h"
#include <iostream>

using namespace std;

void linear::ShowResults() {

	cout << "Линейная модель" << endl << endl;
	cout.width(8);
	cout << "y" << " |  " << "u" << "  | " << "t" << endl << endl;
	y[0] = 0;
	for (int t = 1; t <= 10; t++) {
		cout.width(8);
		y[t] = 0.988*y[t-1] + 0.232*u;
		cout << y[t-1] << " | " << u << " | " << t << endl;
	}
};


```
notlinear.h:
```c++

#pragma once
#include "parent.h"


class notlinear : public parent {
public:

	void ShowResults();

};
```
parent.h:
```c++
#pragma once
#include <iostream>


class parent {
public:
	
	virtual void ShowResults() = 0;
protected:
	double y[12];
	const int u = 100;
};

```

linear.h
```c++
#pragma once
#include "parent.h"

class linear : public parent {
public:

	void ShowResults();
};

```
main.cpp
```c++
#include "stdafx.h"
#include "linear.h"
#include "notlinear.h"
#include <iostream>

using namespace std;


int main() {
	setlocale(0, "");
	linear lin;
	notlinear notlin;
	lin.ShowResults();
	cout << endl << endl;
	notlin.ShowResults();
	return 0;
}

```

Вывод: Реализовал программу, моделирующую объект управления на С++. Построил графики моделей температуры объекта. Температура обьекта зависит от входной температуры линейно и нелинейно в зависимости от объекта.