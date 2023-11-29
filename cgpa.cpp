#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
struct Course{
    string name;
    int creditHours;
    double grade;
};
double CGPA_CALCULATOR(const vector<Course>&courses){
double totalgradepoints=0.0;
int totalcreditHours=0;
for(const Course&course:courses){
    totalgradepoints+=course.grade*course.creditHours;
    totalcreditHours+=course.creditHours;
}
if(totalcreditHours>0){
    return totalgradepoints/totalcreditHours;
}
else{
    return 0.0;
}
}
int main()
{
    vector<Course>courses;
    cout<<"CGPA Calculator"<<endl;
    int numCourses;
    cout<<"ENTER THE NUMBER OF COURSES"<<endl;
    cin>>numCourses;

    for(int i=0;i<numCourses;i++){
        Course newcourse;
        cout<<"\nENTER THE DETAILS OF COURSE";
        cout<<"\nCOURSE NAME";
        cin.ignore();
        getline(cin,newcourse.name);
        cout<<"CREDIT HOURS";
        cin>>newcourse.creditHours;
        cout<<"Grade(1-9):";
        cin>>newcourse.grade;
        if(newcourse.grade<1||newcourse.grade>9){
            cout<<"INVALID GRADE.PLEASE ENTER GRADE BETWEEN 1-9"<<endl;
            i--;
            continue;
        }
        courses.push_back(newcourse);
    }
    double CGPA=CGPA_CALCULATOR(courses);
    cout<<fixed<<setprecision(2);
    cout<<"\nYOUR CGPA IS:"<<CGPA<<endl;
    return 0;

    }
