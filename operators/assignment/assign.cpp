//
// Created by Никита Степанов on 17.02.2024.
//

#include "assign.h"

// Перегрузка оператора присваивания (=)
Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numer = other.numer;
        denom = other.denom;
        simplify();
    }
    return *this;
}

// Перегрузка оператора равенства (==)
bool Rational::operator==(const Rational& other) const {
    return numer == other.numer && denom == other.denom;
}