#pragma once
#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    explicit Person(const std::string &name);
    virtual ~Person() = default;
    virtual const std::string &get_name() const;

private:
    std::string name;
};

class Professor : public Person {
public:
    Professor(const std::string &name, const std::string &department_name);
    const std::string &get_department_name() const;

private:
    std::string department_name; // 소속 학과
};

class Student : public Person {
public:
    Student(const std::string &name, int grade);
    int get_grade() const;

private:
    int grade; // 1학년~4학년
};

class Lecture {
public:
    Lecture(const std::string &name, const Professor &professor, const std::vector<Student> &students);
    void add_student(const Student &student);
    const std::string &get_name() const;
    const Professor &get_professor() const;
    const std::vector<Student> &get_students() const;

private:
    std::string name;
    Professor professor;
    std::vector<Student> students;
};
