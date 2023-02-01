#include "quiz.h"

int main() {
    Cat cat(1, 2);
    print_obj(cat); // (1,2)
    move_right(cat);
    print_obj(cat); // (2,2)
    move_up(cat);
    print_obj(cat); // (2,3)
    move_left(cat);
    print_obj(cat); // (1,3)
    move_down(cat);
    print_obj(cat); // (1,2)

    Tree tree(0, 3);
    print_obj(tree); // (0,3)
    return 0;
}
