#include "Course.hpp"
#include "Student.hpp"
#include <iostream>
#include <string>
using namespace std;

//defult ctor
Course::Course() : courseName(string()), courseNum(0), studentList(NULL), signedStudNum(0), studGrades(NULL){}

//ctor
Course::Course (int courseNum, string courseName) : courseName(courseName), courseNum(courseNum), studentList(NULL), signedStudNum(0), studGrades(NULL) {}

Course::Course(int courseNum) : courseName(string()), courseNum(courseNum), studentList(NULL), signedStudNum(0), studGrades(NULL){}

//cctor
Course::Course(const Course& other) : courseName(other.courseName), courseNum(other.courseNum),signedStudNum(other.signedStudNum) {
    if (signedStudNum > 0) {
        this->studentList = new Student*[signedStudNum];
        this->studGrades = new int[signedStudNum];
        for (int i = 0; i < signedStudNum; i++) {
            studentList[i] = other.studentList[i];
            studGrades[i] = other.studGrades[i];
        }
    } else {
        studentList = NULL;
        studGrades = NULL;
    }
}

//dtor
Course::~Course(){
    for (int i = 0; i < signedStudNum; i++)
        delete[] studentList[i];
    delete [] studentList;
    
    if(studGrades)
        delete [] studGrades;
   
}
//operator =
Course& Course::operator = (const Course& object){
    if(this != &object){
        if(studentList){
            for (int i = 0; i < signedStudNum; i++)
                delete studentList[i];
            delete[] studentList;
        }
        if(studGrades){
            delete [] studGrades;
        }
        courseName = object.courseName;
        signedStudNum = object.signedStudNum;
        this->studentList = new Student*[signedStudNum];
        assert(studentList);
        this->studGrades = new int[signedStudNum];
        assert(studGrades);
        for (int i = 0; i<signedStudNum; i++) {
            studentList[i] = new Student();
            studGrades[i] = object.studGrades[i];
        }
        for (int i = 0; i<signedStudNum; i++){
            *(this->studentList[i]) = *(object.studentList[i]);
        }
        
    }
    
    return *this;
}

//operator ==
bool Course::operator== (const Course& object)const {
    return courseNum == object.courseNum;;
}

//operator +=
Course& Course::operator += (const Student& student) {
    int i;
    Student** temp = new Student*[++signedStudNum];
    for(i=0; i<signedStudNum-1; i++){
        temp[i] = studentList[i];
    }
    temp[i] = new Student(student);
    if(studentList){
        delete [] studentList;
    }
    this->studentList = temp;
    return *this;
}

//operator >>
istream& operator >> (istream& input, Course& obj) {
    cout << "Enter course's name: \n";
    input >> obj.courseName;
    cout << "Enter course's number: \n";
    input >> obj.courseNum;
    return input;
}

//operator <<
ostream& operator << (ostream& output, const Course& obj){
    output << "Course name: "<< obj.courseName << "\nCourse ID: " << obj.courseNum <<"\nNumber of students in course: "<< obj.signedStudNum<< endl;
    if(obj.signedStudNum>0){
        for (int i = 0; i < obj.signedStudNum; i++){
            output << *(obj.studentList[i]);
            cout<<"Grade in course: ";
            if(obj.studGrades[i] == -1){
                cout<<"The Grade Is Not Updated ! \n";
            }
            else{
                output << obj.studGrades[i];
                output << endl;
            }
        }
        
    }
    else{
        cout<<"No students in this course. \n";
    }
    return output;
}

void Course::print()const{
    cout << '(' << this->courseName << ',' << this->courseNum << ')' << endl;
}
void Course::setCourseNum(int NcourseNumber){
    courseNum = NcourseNumber;
}

void Course::addGrade(int grade){
    int i;
    int* temp = new int[signedStudNum];
    for(i=0; i<signedStudNum-1 ;i++){
        temp[i] = studGrades[i];
    }
    temp[i] = grade;
    if(studGrades)
        delete [] studGrades;
    studGrades = temp;
}

bool Course::checkIfStudentRegisteredToCourse(Student student){
    for (int i=0; i < signedStudNum; i++){
        if(student == *studentList[i]){
            cout << "The student is already registered to the course." <<endl;
            return true;
        }
    }
    return false;
}


void Course::setName(string courseName){
    this->courseName = courseName;
}

void Course::setNewGrade(int position, int grade){
    this->studGrades[position] = grade;
}
