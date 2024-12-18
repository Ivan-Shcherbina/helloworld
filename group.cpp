//group.cpp
#include <iostream>
#include "group.h"

Group::Group() {
    std::cout << "Enter group name: ";
    std::cin >> number;
    first = nullptr;
}

Group::~Group() {
    Student* current = first;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }
    std::cout << "All elements are deleted\n";
}

void Group::addStudent() {
    Student* newStudent = new Student;
    newStudent->setName();
    newStudent->next = first;
    first = newStudent;
}

void Group::display() {
    Student* current = first;
    std::cout << "Group: " << number << "\n";
    int i = 1;
    while (current != nullptr) {
        std::cout << i++ << ". " << current->getName() << "\n";
        current = current->next;
    }
}

float Group::getAverageRating() {
    float totalRating = 0;
    int count = 0;
    Student* current = first;
    while (current != nullptr) {
        totalRating += current->getRating();
        count++;
        current = current->next;
    }
    return (count > 0) ? totalRating / count : 0;
}
