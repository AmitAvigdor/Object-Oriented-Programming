#ifndef Course_hpp
#define Course_hpp
#include <iostream>
#include <string>
#include "Student.hpp"
using namespace std;

class Student;
class Course{

private:
    string courseName;
    int courseNum;
    Student** studentList ;  //dynamic
    int signedStudNum;
    int *studGrades;        //dynamic
public:
    Course();
    Course(const Course& other);
    Course(int, string);
    Course(int);
    ~Course();

    Course& operator = (const Course&);
    bool operator== (const Course&)const;
    Course& operator += (const Student& obj);
    friend istream& operator >> (istream&,  Course&);
    friend ostream& operator << (ostream&, const Course&);
    void setCourseNum(int);
    void print()const;
    void addGrade(int);
    bool checkIfStudentRegisteredToCourse(Student);
    void setName(string);
    string getCourseName(){return courseName;}
    void setNewGrade(int,int);
   
};


    #endif /* Course_hpp */

