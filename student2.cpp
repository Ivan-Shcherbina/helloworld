#include <iostream>
#include <cstring> 
using namespace std;

class Student {
private:
    char name[40];
    float rating;
    
    static int numberStudents;
    static float totalRating;

public:
    Student() {
        strcpy(name, ""); 
        rating = 0.0; 
    }

    void setData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter rating (60-100): ";
        cin >> rating;

        numberStudents++;
        totalRating += rating;
    }

    void printData() const {
        cout << "Name: " << getName() << ", Rating: " << getRating() << endl;
    }

    const char* getName() const {
        return name;
    }

    float getRating() const {
        return rating;
    }

    static int getNumberStudents() {
        return numberStudents;
    }

    static float getAverageRating() {
        return (numberStudents > 0) ? totalRating / numberStudents : 0;
    }

    static float getTotalRating() {
        return totalRating;
    }

    void setName(const char* n) {
        strcpy(name, n);
    }

    void setRating(float r) {
        rating = r;  
    }
};


int Student::numberStudents = 0;
float Student::totalRating = 0;


class GroupLeader : public Student {
private:
    string position;

public:
    GroupLeader(string n, string pos, float r) {
        setName(n.c_str());
        setRating(r);
        position = pos;      
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
    Student* studPtr[30]; 
    int n = 0;
    char ch;


    do {
        studPtr[n] = new Student;
        studPtr[n]->setData(); 
        n++;

        cout << "Enter next student (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        studPtr[i]->printData(); 
    }

    cout << "Number of students: " << Student::getNumberStudents() << endl;
    cout << "Average rating of group: " << Student::getAverageRating() << endl;

    cout << "Size of studPtr array (30 elements): " << sizeof(studPtr) << " bytes" << endl;
    cout << "Size of one Student object: " << sizeof(Student) << " bytes" << endl;

    GroupLeader leader("Марина Шевченко", "Староста", 90.0);
    leader.compareWithGroupAverage(); 

    for (int i = 0; i < n; i++) {
        delete studPtr[i];
    }

    return 0;
}
