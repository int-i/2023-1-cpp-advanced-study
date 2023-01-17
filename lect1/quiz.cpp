#include "quiz.h"

Person::Person(const std::string &name)
: name(name) {
}

const std::string &Person::get_name() const {
    return name;
}

Professor::Professor(const std::string &name, const std::string &department_name)
: Person(name), department_name(department_name) {
}

const std::string &Professor::get_department_name() const {
    return department_name;
}

Student::Student(const std::string &name, int grade)
: Person(name), grade(grade) {
}

int Student::get_grade() const {
    return grade;
}

Lecture::Lecture(const std::string &name, const Professor &professor, const std::vector<Student> &students)
: name(name), professor(professor), students(students) {
}

void Lecture::add_student(const Student &student) {
    students.push_back(student);
}

const std::string &Lecture::get_name() const {
    return name;
}

const Professor &Lecture::get_professor() const {
    return professor;
}

const std::vector<Student> &Lecture::get_students() const {
    return students;
}
