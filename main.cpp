#include <iostream>
#include "rational/rational.h"

int main() {
    Rational rat(25, 1);
    Rational lol(10, 12);
    std::cout << rat.sqrt(2);
    return 0;
}
