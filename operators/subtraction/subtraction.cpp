//
// Created by Никита Степанов on 16.02.2024.
//

#include "subtraction.h"

// Перегрузка оператора вычитания (-)
Rational Rational::operator-(const Rational& other) const {
    int num1 = numer * other.denom - other.numer * denom;
    int denom1 = denom * other.denom;
    return Rational(num1, denom1);
}

// Перегрузка оператора вычитания с присваиванием (-=)
Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

// Перегрузка оператора вычитания для long long
Rational Rational::operator -(long long value) const {
    int num = numer - value * denom;
    return Rational(num, denom);
}

// Перегрузка оператора вычитания с присваиванием для long long
Rational& Rational::operator -=(long long value) {
    numer -= value * denom;
    return *this;
}
