#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

class Model {
    public:
        virtual float equation(double warm, double y) = 0;
};

class Linear : public Model {
    private:
        float a, b;

    public:
        Linear(const float a, const float b) {
            this->a = a;
            this->b = b;
        }
        float equation(double warm, double y) override {
            y = a * y + b * warm;
            return y;
        }
};

class Nonlinear : public Model {
    private:
        float a, b, c, d;
        double y0 = 0;
        double warm0 = 0;

    public:
        Nonlinear(float a, float b, float c, float d) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
        }
        float equation(double warm, double y) override {
            double y1 = a * y - b * pow(y0, 2) + c * warm + d * sin(warm0);
            y0 = y;
            warm0 = warm;
            return y1;
        }
};

class Regulator {
    private:
        double warm = 0;
        double K, T, TD, T0;

    public:
        Regulator(const double K, const double T0, const double TD, const double T) {
            this->K = K;
            this->T0 = T0;
            this->TD = TD;
            this->T = T;
        }
        double Warm(const double e, const double e0 = 0, const double e1 = 0) {
            double q0 = K * (1.0 + TD / T0);
            double q1 = -K * (1 + 2.0 * TD / T0 - T0 / T);
            double q2 = K * TD / T0;
            warm += q0 * e + q1 * e0 + q2 * e1;
            return warm;
        }
};

void PIDRegulator(const double w, Regulator* ins, Model* m, double y, int n) {
    double e = 0.0, e0 = 0.0, e1 = 0.0;
    double u = 0;

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << e << "\t\t\t" << y << "\t\t\t" << u << endl;
        e = w - y;
        u = ins->Warm(e, e0, e1);
        y = m->equation(u, y);
        e1 = e0;
        e0 = e;
    }
}

int main() {
    int n = 0;
    enter:
    cout << "Enter the number of iterations: ";
    cin >> n;

    if (n <= 0) {
        cout << "Enter a large number." << endl;
        goto enter;
    }
    else if (n > 50) {
        cout << "Enter a smaller number." << endl;
        goto enter;
    }
    else {
        cout << "\nLinear model:\n" << "E" << "\t\t\t\t" << "Y" << "\t\t\t\t" << "U" << endl;
        cout << "_____________________________________________________________________________" << endl;
        Linear* l = new Linear(0.3, 0.1);
        Regulator* lr = new Regulator(0.081, 4, 0.22, 0.43);
        PIDRegulator(10, lr, l, 0, n);

        cout << "\nNonlinear model:\n" << "E" << "\t\t\t\t" << "Y" << "\t\t\t\t" << "U" << endl;
        cout << "_____________________________________________________________________________" << endl;
        Nonlinear* nl = new Nonlinear(0.2, 0.0001, 0.1, 0.0002);
        Regulator* nlr = new Regulator(0.8, 7, 30, 9);
        PIDRegulator(10, nlr, nl, 0, n);
    }
    return 0;
}