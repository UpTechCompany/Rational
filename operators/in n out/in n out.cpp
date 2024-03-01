//
// Created by Никита Степанов on 23.02.2024.
//

#include "in n out.h"

std::ostream& operator<<(std::ostream& out, const Rational& rational) {
    out << rational.numer << "/" << rational.denom;
    return out;
}

// Перегрузка оператора ввода >>
std::istream& operator>>(std::istream& in, Rational& rational) {
    // Предполагаем формат "числитель/знаменатель"
    char slash;
    in >> rational.numer >> slash >> rational.denom;
    // Проверяем, что ввод корректен
    if (slash != '/') {
        // Если разделитель не является '/', устанавливаем флаг ошибки
        in.setstate(std::ios::failbit);
    } else if (rational.denom == 0) {
        // Проверяем, что знаменатель не равен нулю
        in.setstate(std::ios::failbit);
    }
    return in;
}

// Перегрузка оператора последовательности (,)
Rational Rational::operator ,(const Rational& other) const {
    // Возвращаем другой объект, значение первого игнорируется
    return Rational(other);
}