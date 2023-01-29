#include <iostream>

template<typename T>
class Animal {
public:
    Animal(int x, int y)
    : x(x), y(y) {}

    void move(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print() const {
        (static_cast<const T &>(*this)).print();
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }

private:
    int x;
    int y;
};

class Cat : public Animal<Cat> {
public:
    Cat(int x, int y)
    : Animal(x, y) {}

    void print() const {
        std::cout << "Cat: " << get_x() << ", " << get_y() << "\n";
    }
};

template<typename T>
void print_animal(const Animal<T> &animal) {
    animal.print();
}

template<typename T>
void move_right(Animal<T> &animal) {
    animal.move(animal.get_x() + 1, animal.get_y());
}
