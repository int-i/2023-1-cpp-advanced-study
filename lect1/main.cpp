#include <iostream>
#include "quiz.h"

int main() {
    Student kim("김**", 100);
    Student lee("이**", 90);
    Student park("박**", 80);
    Professor choi("최**", "정보통신공학과");

    Lecture cpp("C++ 심화", choi, { kim, lee });

    std::cout << cpp.get_name() << " 성적\n";
    for (const Student &student : cpp.get_students()) {
        std::cout << student.get_name() << ": " << student.get_grade() << '\n';
    }

    cpp.add_student(park);
    std::cout << '\n';

    std::cout << cpp.get_name() << " 성적\n";
    for (const Student &student : cpp.get_students()) {
        std::cout << student.get_name() << ": " << student.get_grade() << '\n';
    }

    return 0;
}
