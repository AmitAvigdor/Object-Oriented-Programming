#ifndef Student_hpp
#define Student_hpp
#include "Course.hpp"
#include <iostream>
#include <string>

using namespace std;
class Course;
class Student{

private:
    string studName;
    string id;
    char gender;
    int age;
    Course** courseList; //dynamic
    int amountOfCourses;

public:
    Student();
    Student(string);
    Student(const Student& other);
    ~Student();

    Student& operator = (const Student&);
    bool operator == (const Student&)const;
    Student& operator += (Course);
    friend istream& operator >> (istream&,  Student&);
    friend ostream& operator << (ostream&, const Student&);

    void setCourseList(Course**,int);
    void printStudent()const;
    bool checkIfCourseRegisteredToStudent(Course);
    Course** getCourseList() {return courseList;}
    void setName(string);
    void setGender(char);
    void setAge(int);
    string getName() {return studName;}
    int getAmount(){return amountOfCourses;}
};



#endif /* Student_hpp */

