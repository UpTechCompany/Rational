//
// Created by Никита Степанов on 16.02.2024.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iostream>
#include "rational.h"
#include <cmath>

class Rational {
private:

    long long numer;
    long long denom;

public:

    Rational();

    explicit Rational(const Rational &numerator, const Rational &denominator);

    explicit Rational(Rational &number);

    explicit Rational(const Rational &number);

    explicit Rational(long long int _number);

    explicit Rational(long long int _numer, long long int _denom);

    explicit Rational(Rational rational, long long number);

    explicit Rational(int number, Rational rational);

    long long getNumerator() const;
    long long getDenominator() const;

    void simplify();

    Rational& operator =(const Rational &number);
    bool operator ==(const Rational& number) const;

    bool operator >=(const Rational& number) const;
    bool operator >(const Rational& number) const;

    bool operator <=(const Rational& number) const;
    bool operator <(const Rational& number) const;

    Rational& operator +=(const Rational& number);
    Rational operator +(const Rational& number) const;

    Rational& operator -=(const Rational& number);
    Rational operator -(const Rational& number) const;

    Rational operator /(const Rational& number) const;
    Rational& operator /=(const Rational& number);

    Rational operator %(const Rational& number) const;
    Rational& operator %=(const Rational& number);

    Rational operator *(const Rational& number) const;
    Rational& operator *=(const Rational& number);

    //______________________________________________//

    Rational operator/(long long value) const;
    Rational& operator/=(long long value);

    Rational& operator*=(long long value);
    Rational operator*(long long value) const;

    Rational& operator%=(long long value);
    Rational operator%(long long value) const;

    Rational& operator-=(long long value);
    Rational operator-(long long value) const;

    Rational operator +(long long value) const;
    Rational& operator +=(long long value);

    bool operator==(long long value) const;
    bool operator<=(long long value) const;
    bool operator>=(long long value) const;
    bool operator<(long long value) const;
    bool operator>(long long value) const;

    friend std::ostream& operator <<(std::ostream& os, const Rational& number);
    friend std::istream& operator >>(std::istream& os, Rational& number);

    Rational operator ,(const Rational& other) const;

    Rational& operator++();

    Rational operator++(int);

    Rational& operator--();

    Rational operator--(int);

    Rational operator ^(int n) const {
        if (n == 0) {
            return Rational(1, 1); // Любое число в степени 0 равно 1
        } else if (n < 0) {
            // Для отрицательной степени инвертируем дробь и берем модуль степени
            Rational inverted = this->invert();
            return inverted ^ (-n);
        } else {
            Rational result(1, 1);
            for (int i = 0; i < n; ++i) {
                result = result * (*this); // Последовательно умножаем на себя n раз
            }
            return Rational(result);
        }
    }

    Rational invert() const {
        return Rational(denom, numer);
    }

    long long isLongLongRange(long long value) const {
        if (value >= std::numeric_limits<long long>::min() && value <= std::numeric_limits<long long>::max()){
            return value;
        } else {
            throw "Overflow";
        }
    };

    long double sqrts() {
        long long p = numer;
        long long q = denom;
        long double x0 = sqrt(static_cast<long double>(p) / q); // начальное приближение
        long double x = x0;

        for (int i = 0; i < 4; ++i) {
            x = 0.5L * (x + p / (q * x)); // метод последовательных приближений
        }

        return x;
    };


};


#endif //RATIONAL_RATIONAL_H
