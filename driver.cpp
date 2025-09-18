#include <iostream>
#include <limits>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
using namespace std;

static void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    LinkedList<Student> list;
    int choice;

    while (true) {
        cout << "1. Insert Student" << endl
             << "2. Delete Student" << endl
             << "3. Search Student" << endl
             << "4. Display All" << endl
             << "5. Count Students" << endl
             << "6. Add a course" << endl
             << "7. Exit" << endl
             << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearLine();
            cout << "Invalid choice. Try again." << endl << endl;
            continue;
        }
        clearLine();

        if (choice == 7) break;

        if (choice == 1) {
            int id; string name; double gpa;

            cout << "Enter ID: ";
            while (!(cin >> id)) { clearLine(); cout << "Invalid ID. Enter ID: "; }
            clearLine();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            while (!(cin >> gpa)) { clearLine(); cout << "Invalid GPA. Enter GPA: "; }
            clearLine();

            Student s(id, name, gpa);
            list.append(s);
            cout << endl;
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            while (!(cin >> id)) { clearLine(); cout << "Invalid ID. Enter ID to delete: "; }
            clearLine();

            bool deleted = false;
            for (int i = 0; i < list.getLength(); i++) {
                if (list.getElement(i).getId() == id) {
                    list.remove(i);
                    cout << "Deleted student with ID " << id << endl << endl;
                    deleted = true;
                    break;
                }
            }
            if (!deleted) cout << "Student with ID " << id << " not found" << endl << endl;
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            while (!(cin >> id)) { clearLine(); cout << "Invalid ID. Enter ID to search: "; }
            clearLine();

            bool found = false;
            for (int i = 0; i < list.getLength(); i++) {
                Student s = list.getElement(i);
                if (s.getId() == id) {
                    cout << "Found: " << s << endl;
                    cout << "Courses: ";
                    s.printCourses(cout);
                    cout << endl << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student with ID " << id << " not found" << endl << endl;
        }
        else if (choice == 4) {
            cout << "Students in List:" << endl;
            for (int i = 0; i < list.getLength(); i++) {
                Student s = list.getElement(i);
                cout << s << " ";
                if (s.hasCourses()) {
                    cout << endl << "Courses: ";
                    s.printCourses(cout);
                } else {
                    cout << "None";
                }
                cout << endl;
            }
            cout << endl;
        }
        else if (choice == 5) {
            cout << "Total students: " << list.getLength() << endl << endl;
        }
        else if (choice == 6) {
            int id;
            cout << "Enter ID: ";
            while (!(cin >> id)) { clearLine(); cout << "Invalid ID. Enter ID: "; }
            clearLine();

            string cname, loc;
            cout << "Enter Course Name: ";
            getline(cin, cname);
            cout << "Enter location: ";
            getline(cin, loc);

            bool updated = false;
            for (int i = 0; i < list.getLength(); i++) {
                Student s = list.getElement(i);
                if (s.getId() == id) {
                    s.addCourse(cname, loc);
                    list.replace(i, s);
                    cout << endl;
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Student with ID " << id << " not found" << endl << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl << endl;
        }
    }
    return 0;
}
