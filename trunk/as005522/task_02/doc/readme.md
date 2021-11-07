          MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                      EDUCATIONAL INSTITUTION 
                «BREST STATE TECHNICAL UNIVERSITY»        
                        Department of IIT


                       Laboratory work No.2 


                                	Completed by the 3rd year student of 
                               		Faculty of Electronic Information Systems
                                	the group AC-55 Rodion E.S.
                             		Checked by Ivanuk D.S.


                             Brest 2021

```
#include<iostream>
#include<math.h>
using namespace std;

class LModel
{
public:
    virtual double Expr(double ut, double y) = 0;
};

class LinModel : public LModel
{
private:
    double a, b;
public:
    LinModel(double a, double b)
    {
        this->a = a;
        this->b = b;
    }

    double Expr(double ut, double y) override
    {
        double yL = 0;
        yL = a * yL + b * ut;
        return yL;
    }
};

class NLinModel : public LModel
{
private:
    double a, b, c, d;
public:
    NLinModel(double a, double b, double c, double d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    double Expr(double ut, double y) override
    {
        double yNL = 0;
        yNL = a * yNL - b * pow(yNL, 2) + c * ut + d * sin(ut);
        return yNL;
    }
};

class Controller
{
private:
    double K, T, TD, T0, cont = 0;
public:
    Controller(const double K, const double T0, const double TD, const double T)
    {
        this->K = K;
        this->T0 = T0;
        this->TD = TD;
        this->T = T;
    }
    double Cont(const double ek, const double ek1, const double ek2)
    {
        double q0, q1, q2;
        q0 = K * (1 + TD / T0);
        q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        q2 = K * TD / T0;
        cont += q0 * ek + q1 * ek1 + q2 * ek2;
        return cont;
    }
};

void PIDRegulator(const double p, Controller* c, LModel* lgm, double y)
{
    double ek=0, ek1=0, ek2=0, u=0;
    for (int k = 0; k < 10; k++)
    {
        cout << ek << "\t\t" << y << "\t\t" << u << "\t\t" << endl;
        ek = p - y;
        u = c->Cont(ek, ek1, ek2);
        y = lgm->Expr(u, y);
        ek2 = ek1;
        ek1 = ek;
    }
}

int main()
{
    cout << "Linear Model Simulation:\n\n[e(k)]\t\t[y]\t\t[u]\n\n";
    LinModel* lm = new LinModel(0.1, 0.2);
    Controller* lmc = new Controller(0.1, 0.2, 0.3, 0.4);
    PIDRegulator (10, lmc, lm, 5);

    cout << "_______________________________________________\n\n\n";

    cout << "Noninear Model Simulation:\n\n[e(k)]\t\t[y]\t\t[u]\n\n";
    NLinModel* nlm = new NLinModel(0.1, 0.2, 0.3, 0.4);
    Controller* nlmc = new Controller(0.1, 0.2, 0.3, 0.4);
    PIDRegulator(10, nlmc, nlm, 5);
}
```