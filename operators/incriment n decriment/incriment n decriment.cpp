//
// Created by Никита Степанов on 23.02.2024.
//

#include "incriment n decriment.h"

// Перегрузка оператора инкремента (++)
Rational& Rational::operator ++() {
    numer += denom;
    return *this;
}

// Перегрузка оператора инкремента (++) в постфиксной форме
Rational Rational::operator ++(int) {
    Rational temp(*this);
    ++(*this);
    return Rational(temp);
}

// Перегрузка оператора декремента (--)
Rational& Rational::operator --() {
    numer -= denom;
    return *this;
}

// Перегрузка оператора декремента (--) в постфиксной форме
Rational Rational::operator --(int) {
    Rational temp(*this);
    --(*this);
    return Rational(temp);
}