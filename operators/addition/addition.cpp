//
// Created by Никита Степанов on 16.02.2024.
//
#include "../../rational/rational.h"

Rational Rational::operator+(const Rational& other) const {
    int num1 = numer * other.denom + other.numer * denom;
    int denom1 = denom * other.denom;
    return Rational(num1, denom1);
}

// Перегрузка оператора сложения с присваиванием (+=)
Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational Rational::operator +(long long value) const {
    int num = Rational::isLongLongRange(numer + denom * value);
    return Rational(num, denom);
}

// Перегрузка оператора +=
Rational& Rational::operator +=(long long value) {
    numer += value * denom;
    return *this;
}

