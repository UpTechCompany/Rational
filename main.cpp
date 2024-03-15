#include <iostream>
#include "rational/rational.h"
#include "vector/vector.h"

int falavelas_algorithm(Vector<int>& warriors, int poison) {
    int remaining_warriors = warriors.getSize();
    int current_index = 0;
    while (remaining_warriors > 1) {
        // Убираем воина, который пьет яд
        warriors.erase(current_index);
        remaining_warriors--;

        // Перемещаемся к следующему воину
        current_index = (current_index + poison - 1) % remaining_warriors;
    }
    return warriors[0]; // Остается последний выживший воин
}


int main() {
    int num_warriors = 666666;
    int poison_step = 16;

    // Создаем вектор воинов с номерами от 1 до num_warriors
    Vector<int> warriors;
    for (int i = 1; i <= num_warriors; ++i) {
        warriors.push_back(i);
    }

    //std::cout << "Воины: " << warriors << std::endl;

    // Решаем задачу Фалавеля
    int last_survivor = falavelas_algorithm(warriors, poison_step);

    std::cout << "Последний выживший воин: " << last_survivor << std::endl;


    // Создаем вектор с начальным размером 5
    Vector<int> vec;

    // Добавляем элементы в конец вектора
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }

    // Выводим элементы вектора
    std::cout << "Элементы вектора: ";
    std::cout << vec << " ";
    std::cout << std::endl;

    // Добавляем элемент в середину вектора
    vec.insert(2, 100);

    // Выводим элементы вектора после вставки
    std::cout << "Элементы вектора после вставки: ";
    std::cout << vec << " ";
    std::cout << std::endl;

    // Удаляем элемент из вектора
    vec.erase(4);

    // Выводим элементы вектора после удаления
    std::cout << "Элементы вектора после удаления: ";
    std::cout << vec << " ";
    std::cout << std::endl;

    std::cout << "Сумма: " << vec.getSum() << std::endl;
    std::cout << "Среднее: " << vec.getAverage() << std::endl;
    std::cout << "Медиана: " << vec.getMedian() << std::endl;

    return 0;
}
//int main() {
//    Rational p(1,2);
//    std::cout << p.sqrts() << " ";
//    Rational rat(25, 1);
//    Rational lol(10, 12);
//    std::cout << rat.sqrt(2);
//    return 0;
//}
