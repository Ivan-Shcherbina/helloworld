#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;

public:
    Student* next;
    Student();  // Конструктор
    void setName();  // Устанавливаем имя
    std::string getName();  // Получаем имя
    float getRating();  // Получаем рейтинг студента

    static int snumber; // Статическая переменная для подсчёта количества студентов
};

#endif
