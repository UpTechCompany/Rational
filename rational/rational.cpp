//
// Created by Никита Степанов on 16.02.2024.
//

#include "rational.h"
#include <cmath>

long long Rational::getNumerator() const {
    return numer;
}

long long Rational::getDenominator() const {
    return denom;
}

Rational::Rational(){
    numer = 0;
    denom = 1;
};

//Rational::Rational(int _numer, int _denom) {
//    numer = _numer;
//    denom = _denom;
//    simplify();
//}

Rational::Rational(long long _numer, long long _denom) {
    numer = _numer;
    denom = _denom;
    simplify();
}

Rational::Rational(long long _number) {
    numer = _number;
    denom = 1;
}

Rational::Rational(const Rational &numerator, const Rational &denominator) {
    this -> numer = numerator.numer * denominator.denom;
    this -> denom = numerator.denom * denominator.numer;
    simplify();
}

Rational::Rational(Rational &number) {
    numer = number.numer;
    denom = number.denom;
    simplify();
}

Rational::Rational(const Rational& rational) {
    numer = rational.numer;
    denom = rational.denom;
    simplify();
}

Rational::Rational(Rational rational, long long number){
    numer = number * rational.denom + rational.numer;
    denom = number * rational.denom + rational.denom;
    simplify();
}

Rational::Rational(int number, Rational rational){
    numer = number * rational.denom + rational.numer;
    denom = number * rational.denom + rational.denom;
    simplify();
}

long long NSD (long long a, long long b){

    while (a != b) {
        if (a > b){
            a -= b;

        } else {
            b -= a;
        }
    }
    return a;

}

void Rational::simplify(){
    long long nod;

    if (denom < 0){
        numer = -numer;
        denom = -denom;
    } else {
        while (NSD(numer, denom) > 1) {
            nod = NSD(numer, denom);
            numer /= nod;
            denom /= nod;
        }
    }
}

double tgamma(double x) {
    if (x <= 0.0) {
        throw std::invalid_argument("Gamma function is not defined for non-positive real numbers.");
    }

    // Интеграл для приближенного вычисления гамма-функции
    // Здесь используется метод Симпсона для вычисления интеграла
    double integral = 0.0;
    double delta = 0.0001; // Шаг интегрирования

    for (double t = delta; t < x; t += delta) {
        double term = (t - delta / 2) * exp(-t);
        integral += 2 * term + 4 * exp(-t - delta / 2);
    }

    integral *= delta / 6;

    return integral * exp(-x);
}

// Метод для вычисления факториала
double factorial(long long n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers.");
    }

    long double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Метод для вычисления квадратного корня с помощью метода Ньютона
Rational Rational::sqrt(int a, int iterations) {
    Rational xn(1);
    for (int i = 0; i < iterations; ++i) {
        Rational temp(xn);

        // При вычислении xn+1 используем числитель и знаменатель xn в явном виде
        xn = Rational(1, a) * (Rational(a - 1) * xn + Rational(*this, xn ^ (a - 1)));
        xn.simplify();

        // Если новое приближение не изменилось (достигнута точность вычисления), выходим из цикла
        if (xn / Rational(10000, 1) == temp / Rational(10000, 1))
            break;
    }
    return  Rational(xn);
}
