#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"
using namespace std;

class Student {
    int id;
    string name;
    double gpa;

    struct CourseNode {
        Course data;
        CourseNode* next;
        CourseNode(const Course& c) : data(c), next(nullptr) { }
    };
    CourseNode* headCourse;

public:
    Student();
    Student(int i, const string& n, double g);
    ~Student();
    Student(const Student& other);
    Student& operator=(const Student& other);

    void setId(int i);
    void setName(const string& n);
    void setGpa(double g);
    int getId() const;
    string getName() const;
    double getGpa() const;

    void addCourse(const string& cname, const string& loc);
    void printCourses(ostream& os) const;
    bool hasCourses() const;
};

ostream& operator<<(ostream& os, const Student& s);

#endif
