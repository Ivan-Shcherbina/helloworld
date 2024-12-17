#include "group.h"
#include <iostream>

int main() {
    Group group;
    char ch;

    do {
        group.addStudent();
        std::cout << "Enter next (y/n): ";
        std::cin >> ch;
    } while (ch == 'y');

    group.display();
    std::cout << "Number of students: " << Student::snumber << "\n";
    std::cout << "Average rating of the group: " << group.getAverageRating() << "\n";

    return 0;
}
