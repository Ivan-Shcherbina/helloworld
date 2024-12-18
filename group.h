//goup.h
#ifndef GROUP_H
#define GROUP_H

#include "student.h"
#include <string>

class Group {
private:
    Student* first;
    std::string number;

public:
    Group();  // Конструктор
    ~Group(); // Деструктор

    void addStudent();  // Добавить студента
    void display();     // Вывести список студентов

    float getAverageRating();  // Для подсчёта среднего рейтинга студентов
};

#endif
