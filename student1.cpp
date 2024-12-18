#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string groupNumber;

    Student(string n, string g, int a, float avg) {
        name = n;
        groupNumber = g;
        age = a;
        averageGrade = avg;
    }

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    float getAverageGrade() const {
        return averageGrade;
    }

    void setAverageGrade(float newGrade) {
        averageGrade = newGrade;
    }

private:
    int age;
    float averageGrade;
};

void printStudentInfo(const Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Group: " << student.groupNumber << endl;
    cout << "Age: " << student.getAge() << endl;
    cout << "Average grade: " << student.getAverageGrade() << endl << endl;
}

int main() {
    Student student1("Іван Петров", "КНТ-513", 20, 85.5);
    Student student2("Марія Шевченко", "КНТ-513", 21, 92.0);
    Student student3("Олександр Коваль", "КНТ-523", 22, 76.5);
    Student student4("Наталія Левченко", "КНТ-523", 19, 88.0);
    Student student5("Дмитро Сидоренко", "КНТ-514", 23, 65.0);

    cout << "Student 1:" << endl;
    printStudentInfo(student1);

    cout << "Student 2:" << endl;
    printStudentInfo(student2);

    cout << "Student 3:" << endl;
    printStudentInfo(student3);

    cout << "Student 4:" << endl;
    printStudentInfo(student4);

    cout << "Student 5:" << endl;
    printStudentInfo(student5);

    student1.setAge(21);
    student1.setAverageGrade(91.5);

    cout << "Updated Student 1:" << endl;
    printStudentInfo(student1);

    return 0;
}
