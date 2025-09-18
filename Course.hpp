#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using namespace std;

class Course {
    string name;
    string location;

public:
    Course();
    Course(const string& n, const string& loc);
    string getName() const;
    string getLocation() const;
};

#endif
