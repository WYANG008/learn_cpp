#include<iostream>

/**
 * static member belongs to class or struct, all instance shares the same value globally
 **/
struct Entity {
    static int x, y;

    void Print() {
        std::cout << x << y << std::endl;
    }
};


int main() {
    Entity e1;
    Entity::x = 4;
    Entity::y = 5;

    e1.Print();

    std::cin.get();

}