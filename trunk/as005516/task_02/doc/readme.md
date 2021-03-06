МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ «БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ» КАФЕДРА ИИТ

                                            Лабораторная работа №2
                                     Моделирование управляемого объекта











                                                                            Выполнил:
                                                                            студент 3 курса
                                                                            группы АС-55
                                                                            Петров В.И.

                                                                            Проверил:
                                                                            Иванюк Д.С.









                                              Брест, 2021

Задание
На C++ реализовать программу, моделирующую ПИД-регулятор. В качестве объекта управления использовать математическую модель, полученную в предыдущей работе. Использовать ООП, в программе должно быть не менее 3-х классов (+наследование).

```

#include<iostream>
#include<math.h>
using namespace std;

class Model
{
public:
virtual float expression(double heat, double y) = 0;
};

class Linear : public Model
{
private:
float a, b;
public:
Linear(const float a, const float b)
{
this->a = a;
this->b = b;
}

    float expression(double heat, double y) override
    {
        y = a * y + b * heat;
        return y;
    }

};

class Non_Linear : public Model
{
private:
float a, b, c, d;
double y0 = 0, heat0 = 0;
public:
Non_Linear(float a, float b, float c, float d)
{
this->a = a;
this->b = b;
this->c = c;
this->d = d;
}

    float expression(double heat, double y) override
    {
        double y1;
        y1 = a * y - b * pow(y0, 2) + c * heat + d * sin(heat0);
        y0 = y;
        heat0 = heat;
        return y1;
    }

};

class Controller
{
private:
double heat = 0;
double K, T, TD, T0;
public:
Controller(const double K, const double T0, const double TD, const double T)
{
this->K = K;
this->T0 = T0;
this->TD = TD;
this->T = T;
}
double Heat(const double e, const double e0 = 0, const double e01 = 0)
{
double q*0, q_1, q_2;
q_0 = K * (1.0 + TD / T0);
q*1 = -K * (1 + 2.0 _ TD / T0 - T0 / T);
q_2 = K _ TD / T0;
heat += q*0 * e + q*1 * e0 + q_2 \* e01;
return heat;
}
};

void PID_System(const double w, Controller* ins, Model* m, double y)
{
double e, e0, e01, u;
e = 0.0,
e0 = 0.0,
e01 = 0.0;
u = 0;
for (int k = 0; k < 300; k++)
{
cout << e << "\t\t" << y << "\t\t" << u << endl;
e = w - y;
u = ins->Heat(e, e0, e01);
y = m->expression(u, y);
e01 = e0;
e0 = e;
}
}

int main()
{
cout << "--- Linear ---\nE\t\tY\t\tU\n";
cout << "----------------------------------------------------" << endl;

    Linear* m = new Linear(0.1, 0.052);
    Controller* r = new Controller(0.2, 3.0, 32.0, 9.0);
    PID_System(25, r, m, 0);

    cout << "\n\n\n--- Non_Linear ---\nE\t\tY\t\tU\n";
    cout << "-----------------------------------------------------" << endl;

    Non_Linear* nl = new Non_Linear(0.2, 0.0002, 0.11, 0.0002);
    Controller* nlr = new Controller(0.7, 6.0, 32.0, 8.0);
    PID_System(25, nlr, nl, 0);
    return 0;

}

```

<p align="center">
  <img src ="../src/images/1111.png">
</p>

<p align="center">
  <img src ="../src/images/2222.png">
</p>

<p align="center">
  <img src ="../src/images/Linear.png">
</p>

<p align="center">
  <img src ="../src/images/Non_Linear.png">
</p>
