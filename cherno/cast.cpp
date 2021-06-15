#include<iostream>


// static cast
// dynamic cast
// reinterpret cast
class Base
{

};

class AnotherClass: public Base {
public:
    AnotherClass() {}
    ~AnotherClass() {}
};

int main() {
    int a = 5;
    double value = a; // implicit cast

    double value2 = 5.25;
    int a = (int)value2; // explicit cast

    double s = static_cast<int>(value2);

}