#include "Student.hpp"
#include <iostream>
#include <string>
using namespace std;

// defult ctor
Student::Student() :studName(string()), id(string()), courseList(NULL), gender('M'), age(NULL), amountOfCourses(0) {
}

//ctor
Student::Student(string Nid) :studName(string()), id(Nid), courseList(NULL), gender('M'), age(NULL), amountOfCourses(0){
}

//cctor
Student::Student(const Student& other) : studName(other.studName), id(other.id),gender(other.gender),age(other.age),amountOfCourses(other.amountOfCourses) {
    if (amountOfCourses > 0) {
        this->courseList = new Course*[amountOfCourses];
        for (int i = 0; i < amountOfCourses; i++) {
            courseList[i] = other.courseList[i];
        }
    } else {
        courseList = NULL;    }
}

//dtor
Student::~Student(){
    for (int i = 0; i < amountOfCourses; i++)
        delete[] courseList[i];
    delete [] courseList;
 
}

//set for courseList
void Student::setCourseList(Course** NcourseList,int NamountOfCourses){
     courseList = new Course*[NamountOfCourses];
     courseList = NcourseList;
}

//operator =
Student& Student::operator = (const Student& object) {
    if(this != &object){
        if(courseList){
            for (int i = 0; i < amountOfCourses; i++)
                delete courseList[i];
            delete[] courseList;
        }
        studName = object.studName;
        amountOfCourses = object.amountOfCourses;
        gender = object.gender;
        age = object.age;
        this->courseList = new Course*[amountOfCourses];
        assert(courseList);
        for (int i = 0; i<amountOfCourses; i++) {
            courseList[i] = new Course();
        }
        for (int i = 0; i<amountOfCourses; i++){
            *(this->courseList[i]) = *(object.courseList[i]);
        }
        
    }

    return *this;
}

//operator ==
bool Student::operator == (const Student& object)const {
//    if(this->id == ""){
//        return false;
//    }
    return this->id == object.id;
}
//operator +=

Student& Student::operator += (Course course) {
    int i;
    Course** temp = new Course*[++amountOfCourses];
    for(i = 0; i<amountOfCourses-1 ;i++ ){
        temp[i] = courseList[i];
    }
    temp[i] = new Course(course);
    if (courseList){
        delete [] courseList;
    }
    this->courseList = temp;
    return *this;
}

//operator >>
istream& operator >> (istream& input, Student& obj) {
    cout << "Enter student's name: \n";
    input >> obj.studName;
    cout << "Enter student's id: \n";
    input >> obj.id;
    cout << "Enter student's gender <F-female/M-male>:  \n";
    input >> obj.gender;
    cout << "Enter student's age: \n";
    input >> obj.age;
    return input;
}

//operator <<
ostream& operator << (ostream& output, const Student& obj) {
    cout << "Student's details: " << endl;
    output << "Name: "<< obj.studName << "\nID: " << obj.id <<"\nGender: "<< obj.gender<<"\nAge: "<<obj.age<< endl;
    if(obj.amountOfCourses>0){
        cout << "The Student's Course List: "<< endl;
        for (int i = 0; i < obj.amountOfCourses; i++){
            output << obj.courseList[i]->getCourseName();
            cout<<endl;
        }
       // output << endl;
    }
    else{
        cout<<"The student is not registered to any courses. \n" ;
    }
    return output;
    
}

void Student::printStudent()const{
    cout << '(' << this->studName << ',' << this->id << ',' << this->gender << ',' << this->age << ')' << endl;
}


bool Student::checkIfCourseRegisteredToStudent(Course course){
    for (int i=0; i < amountOfCourses; i++){
        if(course == *courseList[i]){
            cout << "The Course is already registered to student's course list." <<endl;
            return true;
        }
    }
    return false;
}

void Student::setName(string name){
    this->studName = name;
}
void Student::setGender(char gender){
    this->gender = gender;
}
void Student::setAge(int age){
    this->age = age;
}

