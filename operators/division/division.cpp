//
// Created by Никита Степанов on 16.02.2024.
//

#include "division.h"

// Перегрузка оператора деления (/)
Rational Rational::operator/(const Rational& other) const {
    int num1 = numer * other.denom;
    int denom1 = denom * other.numer;
    return Rational(num1, denom1);
}

// Перегрузка оператора деления с присваиванием (/=)
Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

// Перегрузка оператора остатка от деления (%)
Rational Rational::operator %(const Rational& other) const {
    int num1 = (numer) * (other.denom % (other.numer * denom));
    int denom1 = (denom) * (other.denom);
    return Rational(num1, denom1);
}

// Перегрузка оператора остатка от деления с присваиванием (%=)
Rational& Rational::operator %=(const Rational& other) {
    *this = *this % other;
    return *this;
}

// Перегрузка оператора деления для long long
Rational Rational::operator/(long long value) const {
    int denom1 = denom * value;
    return Rational(numer, denom1);
}

// Перегрузка оператора деления с присваиванием для long long
Rational& Rational::operator /=(long long value) {
    denom *= value;
    return *this;
}

// Перегрузка оператора остатка от деления для long long
Rational Rational::operator %(long long value) const {
    int num = numer % (value * denom);
    return Rational(num, denom);
}

// Перегрузка оператора остатка от деления с присваиванием для long long
Rational& Rational::operator%=(long long value) {
    numer %= (value * denom);
    return *this;
}