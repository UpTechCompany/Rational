//
// Created by Никита Степанов on 16.02.2024.
//

#include "multiplication.h"

// Перегрузка оператора умножения (*)
Rational Rational::operator *(const Rational& other) const {
    int num1 = numer * other.numer;
    int denom1 = denom * other.denom;
    return Rational(num1, denom1);
}

// Перегрузка оператора умножения с присваиванием (*=)
Rational& Rational::operator *=(const Rational& other) {
    *this = *this * other;
    return *this;
}

// Перегрузка оператора умножения для long long
Rational Rational::operator *(long long value) const {
    int num = numer * value;
    return Rational(num, denom);
}

// Перегрузка оператора умножения с присваиванием для long long
Rational& Rational::operator *=(long long value) {
    numer *= value;
    return *this;
}