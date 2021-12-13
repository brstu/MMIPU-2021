                                      МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ
                                                УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ 
                                  «БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»
                                                    КАФЕДРА ИИТ








                                                Лабораторная работа №2
                                         	    ПИД-регуляторы











                                                                                Выполнил:
                                                                                студент 3 курса
                                                                                группы АС-55
                                                                                Рахлей А. С.
                                                                                Проверил:
                                                                                Иванюк Д. С.









                                                  Брест 2021 
                                                  
                                                  
                                                  
Цель работы: На C++ реализовать программу, моделирующую рассмотренный выше ПИД-регулятор.
Код:
```c++
#include<iostream>
#include<math.h>

using namespace std;

class Model {
public:
    virtual float expression(double heat, double y) = 0;
};

class Linear : public Model {
private:
    float a, b;
public:
    Linear(float a, float b) {
        this->a = a;
        this->b = b;
    }

    float expression(double heat, double y) override {
        return y = a * y + b * heat;
    }
};

class Non_Linear : public Model {
private:
    float a, b, c, d;
    double y_0 = 0, heat_0 = 0;
public:
    Non_Linear(float a, float b, float c, float d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    float expression(double heat, double y) override {
        double y_1;
        y_1 = a * y - b * pow(y_0, 2) + c * heat + d * sin(heat_0);
        heat_0 = heat;
        return y_1 = y;
    }
};

class Controller {
private:
    double heat = 0;
    double K, T, T_D, T_0;
public:
    Controller(double K, double T_0, double T_D, double T) {
        this->K = K;
        this->T_0 = T_0;
        this->T_D = T_D;
        this->T = T;
    }

    double Heat(double e, double e_0 = 0, double e_01 = 0) {
        double q_0, q_1, q_2;
        q_0 = K * (1.0 + T_D / T_0);
        q_1 = -K * (1 + 2.0 * T_D / T_0 - T_0 / T);
        q_2 = K * T_D / T_0;
        return heat += q_0 * e + q_1 * e_0 + q_2 * e_01;
    }
};

void PID_System(double w, Controller* ins, Model* m, double y) {
    double e = 0, e_0 = 0, e_01 = 0, u = 0;
    for (int i = 0; i < 50; i++) {
        cout << e << "\t\t" << y << "\t\t" << u << endl;
        e = w - y;
        u = ins->Heat(e, e_0, e_01);
        y = m->expression(u, y);
        e_01 = e_0;
        e_0 = e;
    }
}

int main() {
    cout << "Linear:\nE\t\tY\t\tU" << endl;
    Linear* m = new Linear(0.33, 0.123);
    Controller* r = new Controller(0.14, 10, 20, 30);
    PID_System(25, r, m, 0);

    cout << "\n\nNon_Linear:\nE\t\tY\t\tU" << endl;
    Non_Linear* nl = new Non_Linear(0.33, 0.123, 0.123, 0.123);
    Controller* nlr = new Controller(0.11, 10, 20, 30);
    PID_System(25, nlr, nl, 0);
}
```
Вывод: Я реализовать программу, моделирующую рассмотренный выше ПИД-регулятор.

