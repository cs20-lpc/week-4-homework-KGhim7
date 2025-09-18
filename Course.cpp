#include "Course.hpp"

Course::Course() : name(""), location("") { }
Course::Course(const string& n, const string& loc) : name(n), location(loc) { }
string Course::getName() const { return name; }
string Course::getLocation() const { return location; }
