#include <iostream>
#include <string>
using namespace std;

class Food {
public:
    string name;
    float price;

    Food(string s, float p, float w) {
        name = s;
        price = p;
        weight = w;
    }

    float getWeight() const {
        return weight;
    }

private:
    float weight;
};

int main() {
    float totalWeight = 0;
    float totalPrice = 0;

    Food orange1("Valencia", 21, 96);
    Food orange2("Tarocco", 22, 105);

    cout << "totalPriceOranges = " << orange1.price + orange2.price << endl;
    cout << "totalWeightOranges = " << orange1.getWeight() + orange2.getWeight() << endl;

    Food apple[3] = {
        Food("Golden", 10.50, 112),
        Food("McIntosh", 11.99, 100),
        Food("Jonathan", 12, 120)
    };

    for (int i = 0; i < 3; i++) {
        totalPrice += apple[i].price;
        totalWeight += apple[i].getWeight();
    }

    cout << "totalPriceApples = " << totalPrice << endl;
    cout << "totalWeightApples = " << totalWeight << endl;

    Food banana1("Cavendish", 15, 120);
    Food banana2("Lady Finger", 18, 115);

    cout << "totalPriceBananas = " << banana1.price + banana2.price << endl;
    cout << "totalWeightBananas = " << banana1.getWeight() + banana2.getWeight() << endl;

    //sizeof
    cout << "Size of Food class: " << sizeof(Food) << " bytes" << endl;
    cout << "Size of orange1 object: " << sizeof(orange1) << " bytes" << endl;

    // cout << "Weight of orange1 = " << orange1.weight << endl;  // Ошибка компиляции

    return 0;
}
