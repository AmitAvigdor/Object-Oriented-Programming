#ifndef Menu_hpp
#define Menu_hpp
#include <iostream>
#include <string>
#include "Course.hpp"
#include "Student.hpp"
using namespace std;


class Student;
class Course;

class Menu{

private:
    Course **allCoursesList;
    int numAllCourses;
    Student **allStudList;
    int numAllStud;
public:
    Menu();
    Menu(const Menu& other);
    Menu(Course**,int,Student**,int);
    ~Menu();
    void Courseprint()const;
    void Studentprint()const;
    void Run();
    void addCourse();
    void addStud();
    void signingStudent();
    void addGradeToStudent();
    void printCourse();
    void printStud();
    void printstudentList();
    void updateAllStudList();
    void updateAllCourseList();
    int printMenu();
    bool checkIfStudentExistInMenu(Student*);
    bool checkIfCourseExistInMenu(Course*);
    void updateStudentAndCourse(Student,Course);

    
};

#endif /* Menu_hpp */
