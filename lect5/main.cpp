#include "quiz.h"

int main() {
    Cat cat(1, 2);
    print_animal(cat); // (1,2)
    move_right(cat);
    print_animal(cat); // (2,2)
    move_up(cat);
    print_animal(cat); // (2,3)
    move_left(cat);
    print_animal(cat); // (1,3)
    move_down(cat);
    print_animal(cat); // (1,2)
    return 0;
}
