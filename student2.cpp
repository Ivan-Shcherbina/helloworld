#include <iostream>
#include <cstring>  // Для strcpy
using namespace std;

class Student {
private:
    char name[40];  // Имя студента
    float rating;   // Рейтинг студента
    
    static int numberStudents;  // Статический член для подсчета студентов
    static float totalRating;   // Статический член для подсчета рейтинга студентов

public:
    // Конструктор с параметрами для инициализации данных
    Student() {
        strcpy(name, "");  // Инициализация имени пустой строкой
        rating = 0.0;  // Инициализация рейтинга
    }

    // Метод для ввода данных
    void setData() {
        cout << "Enter name: ";
        cin >> name;  // Вводим имя студента
        cout << "Enter rating (60-100): ";
        cin >> rating;  // Вводим рейтинг студента

        // Увеличиваем количество студентов и суммируем рейтинг
        numberStudents++;
        totalRating += rating;
    }

    // Метод для вывода данных студента
    void printData() const {
        cout << "Name: " << getName() << ", Rating: " << getRating() << endl;
    }

    // Геттеры для имени и рейтинга
    const char* getName() const {
        return name;
    }

    float getRating() const {
        return rating;
    }

    // Статический метод для получения количества студентов
    static int getNumberStudents() {
        return numberStudents;
    }

    // Статический метод для получения среднего рейтинга
    static float getAverageRating() {
        return (numberStudents > 0) ? totalRating / numberStudents : 0;
    }

    // Статический метод для получения общего рейтинга
    static float getTotalRating() {
        return totalRating;
    }

    // Статический метод для изменения имени
    void setName(const char* n) {
        strcpy(name, n);  // Копируем имя
    }

    // Статический метод для изменения рейтинга
    void setRating(float r) {
        rating = r;  // Устанавливаем рейтинг
    }
};

// Инициализация статических переменных
int Student::numberStudents = 0;
float Student::totalRating = 0;

// Класс старосты группы
class GroupLeader : public Student {
private:
    string position;

public:
    GroupLeader(string n, string pos, float r) {
        setName(n.c_str());  // Устанавливаем имя старосты через метод setName
        setRating(r);        // Устанавливаем рейтинг старосты через метод setRating
        position = pos;      // Устанавливаем позицию
    }

    string getPosition() const {
        return position;
    }

    void compareWithGroupAverage() const {
        float average = getAverageRating();
        if (getRating() > average) {
            cout << "Group leader " << getName() << " has a higher rating than the group average." << endl;
        } else if (getRating() < average) {
            cout << "Group leader " << getName() << " has a lower rating than the group average." << endl;
        } else {
            cout << "Group leader " << getName() << " has the same rating as the group average." << endl;
        }
    }
};

int main() {
    Student* studPtr[30];  // Массив указателей на студентов
    int n = 0;
    char ch;

    // Ввод студентов в цикле
    do {
        studPtr[n] = new Student;  // Создаем объект студента в динамической памяти
        studPtr[n]->setData();  // Вводим данные студента
        n++;

        cout << "Enter next student (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    // Вывод данных всех студентов
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        studPtr[i]->printData();  // Выводим данные студента
    }

    // Вывод общего количества студентов и среднего рейтинга
    cout << "Number of students: " << Student::getNumberStudents() << endl;
    cout << "Average rating of group: " << Student::getAverageRating() << endl;

    // Использование sizeof для определения размера массива и объекта
    cout << "Size of studPtr array (30 elements): " << sizeof(studPtr) << " bytes" << endl;
    cout << "Size of one Student object: " << sizeof(Student) << " bytes" << endl;

    // Создание старосты группы
    GroupLeader leader("Марина Шевченко", "Староста", 90.0);
    leader.compareWithGroupAverage();  // Сравнение рейтинга старосты с средним рейтингом группы

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete studPtr[i];
    }

    return 0;
}
