#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct Course {
    string name;
    int creditHours;
    double grade;
};

double calculateCGPA(const vector<Course>& courses) {
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for (const Course& course : courses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    return (totalCreditHours > 0) ? (totalGradePoints / totalCreditHours) : 0.0;
}

int main() {
    cout << "CGPA Calculator" << endl;

    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses;

    for (int i = 0; i < numCourses; i++) {
        Course newCourse;

        cout << "\nEnter the details of course " << i + 1 << ":";
        cout << "\nCourse Name: ";
        cin.ignore();
        getline(cin, newCourse.name);

        cout << "Credit Hours: ";
        cin >> newCourse.creditHours;

        cout << "Grade (1-9): ";
        cin >> newCourse.grade;

        if (newCourse.grade < 1 || newCourse.grade > 9) {
            cout << "Invalid grade. Please enter a grade between 1-9." << endl;
            i--;
            continue;
        }

        courses.push_back(newCourse);
    }

    double CGPA = calculateCGPA(courses);

    cout << fixed << setprecision(2);
    cout << "\nYour CGPA is: " << CGPA << endl;

    return 0;
}
