#include <iostream>
#include "student.h"

int Student::snumber = 0;  // Инициализация статической переменной

Student::Student() {
    snumber++;
    next = nullptr;
}

void Student::setName() {
    std::cout << "Enter name: ";
    std::cin >> name;
}

std::string Student::getName() {
    return name;
}

float Student::getRating() {
    float rating;
    std::cout << "Enter rating for " << name << ": ";
    std::cin >> rating;
    return rating;
}
