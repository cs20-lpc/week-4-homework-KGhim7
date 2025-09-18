#include "Student.hpp"
#include <iomanip>

Student::Student() : id(0), name(""), gpa(0.0), headCourse(nullptr) { }
Student::Student(int i, const string& n, double g) : id(i), name(n), gpa(g), headCourse(nullptr) { }

Student::~Student() {
    CourseNode* curr = headCourse;
    while (curr != nullptr) {
        CourseNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

Student::Student(const Student& other) : id(other.id), name(other.name), gpa(other.gpa), headCourse(nullptr) {
    CourseNode* tail = nullptr;
    for (CourseNode* p = other.headCourse; p; p = p->next) {
        CourseNode* node = new CourseNode(p->data);
        if (!headCourse) {
            headCourse = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
}

Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;
    id = other.id;
    name = other.name;
    gpa = other.gpa;

    CourseNode* curr = headCourse;
    while (curr) {
        CourseNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    headCourse = nullptr;

    CourseNode* tail = nullptr;
    for (CourseNode* p = other.headCourse; p; p = p->next) {
        CourseNode* node = new CourseNode(p->data);
        if (!headCourse) {
            headCourse = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return *this;
}

void Student::setId(int i) { id = i; }
void Student::setName(const string& n) { name = n; }
void Student::setGpa(double g) { gpa = g; }
int Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::addCourse(const string& cname, const string& loc) {
    CourseNode* node = new CourseNode(Course(cname, loc));
    if (!headCourse) {
        headCourse = node;
    } else {
        CourseNode* curr = headCourse;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
}

bool Student::hasCourses() const {
    return headCourse != nullptr;
}

void Student::printCourses(ostream& os) const {
    if (!headCourse) {
        os << "None";
        return;
    }
    for (CourseNode* p = headCourse; p; p = p->next) {
        os << p->data.getName() << " " << p->data.getLocation();
        if (p->next) os << "\n         ";
    }
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.getId() << " " << s.getName() << " "
       << fixed << setprecision(1) << s.getGpa();
    return os;
}
