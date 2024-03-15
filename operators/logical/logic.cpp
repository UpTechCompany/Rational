//
// Created by Никита Степанов on 16.02.2024.
//

#include "logic.h"
#include "../../rational/rational.h"


// Перегрузка оператора меньше (<)
bool Rational::operator <(const Rational& other) const {
    return numer * other.denom < other.numer * denom;
}

// Перегрузка оператора больше (>)
bool Rational::operator >(const Rational& other) const {
    return other < *this;
}

// Перегрузка оператора меньше или равно (<=)
bool Rational::operator <=(const Rational& other) const {
    return !(*this > other);
}

// Перегрузка оператора больше или равно (>=)
bool Rational::operator >=(const Rational& other) const {
    return !(*this < other);
}

// Перегрузка оператора сравнения "равно" для Rational и long long
bool Rational::operator ==(long long value) const {
    return (numer == value * denom);
}

// Перегрузка оператора сравнения "меньше или равно" для Rational и long long
bool Rational::operator <=(long long value) const {
    return (numer <= value * denom);
}

// Перегрузка оператора сравнения "больше или равно" для Rational и long long
bool Rational::operator >=(long long value) const {
    return (numer >= value * denom);
}

// Перегрузка оператора сравнения "меньше" для Rational и long long
bool Rational::operator <(long long value) const {
    return (numer < value * denom);
}

// Перегрузка оператора сравнения "больше" для Rational и long long
bool Rational::operator>(long long value) const {
    return (numer > value * denom);
}

