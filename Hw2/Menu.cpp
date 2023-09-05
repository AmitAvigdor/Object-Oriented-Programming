
#include "Menu.hpp"
#include <iostream>
#include <string>
using namespace std;


//defult ctor
Menu::Menu() : numAllCourses(0), allCoursesList(NULL), numAllStud(0), allStudList(NULL){}

//cctor
Menu::Menu(const Menu& other):numAllCourses(0), numAllStud(0){
    if (numAllCourses > 0) {
        allCoursesList = new Course*[numAllCourses];
        for (int i = 0; i < numAllCourses; i++) {
            allCoursesList[i] = other.allCoursesList[i];
        }
    } else {
        allCoursesList = NULL;
        
    }
    if (numAllStud > 0) {
        allStudList = new Student*[numAllStud];
        for (int i = 0; i < numAllStud; i++) {
            allStudList[i] = other.allStudList[i];
        }
    } else {
        allStudList = NULL;
        
    }
}

//dtor
Menu::~Menu(){
   for (int i = 0; i < numAllCourses; i++)
        delete[] allCoursesList[i];
    delete[] allCoursesList;

    for (int i = 0; i < numAllStud; i++)
        delete[] allStudList[i];
    delete [] allStudList;
}

//Run method
void Menu::Run(){
    while (1)
    {
        fflush(stdin);
        cout << "*************************************************************************" << endl;
        cout << "*************************************************************************" << endl;
        cout << "*************************************************************************" << endl;
        cout << "Welcome to sce. What would you like to do?" << endl;
        cout << "*************************************************************************" << endl;
        cout << "[1] - Add New Course" << endl;
        cout << "[2] - Add New Studant" << endl;
        cout << "[3] - Register A Studant To Course  " << endl;
        cout << "[4] - Add Grade To Studant " << endl;
        cout << "[5] - Course Details" << endl;
        cout << "[6] - Studant Details" << endl;
        cout << "[7] - Exit" << endl;
        cout << "*************************************************************************" << endl;

        int choice;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            addCourse();
            break;
        case 2:
            addStud();
            break;
        case 3:
            signingStudent();
            break;
        case 4:
            addGradeToStudent();
            break;
        case 5:
            printCourse();
            break;
        case 6:
            printStud();
            break;
        case 7:
            cout << "Thank you, goodbye." << endl;
            return;
            break;
        default:
            cout << "No such option , sorry. Choose again please." << endl;
        }
    }
}

void Menu::Courseprint()const{
    if (numAllCourses) {
        for (int i = 0; i < numAllCourses; i++)
            allCoursesList[i]->print();
    }
    else
        cout << " Empty !"<<endl;
}
void Menu::Studentprint()const{
    if (numAllStud) {
        for (int i = 0; i < numAllStud; i++)
            allStudList[i]->printStudent();
    }
    else
        cout << " Empty !"<<endl;
}


void Menu::addCourse(){
    cout << "Enter Course's Name: " << endl;
    string name;
    cin >> name;
    cout << "Enter Course's Number: " << endl;
    int number;
    cin >> number;
    Course* course = new Course(number, name);

    
    if (checkIfCourseExistInMenu(course)) {
        cout << "A Course with this code already exists." << endl;
        return;
    }
    if (numAllCourses > 0) {
        updateAllCourseList();

    }
    else {
        allCoursesList = new Course * [++numAllCourses];
    }
    allCoursesList[numAllCourses - 1] = course;
    cout << "Course added." << endl;
}
     
void Menu::addStud(){
    string tempName;
    string tempId;
    char tempGender;
    int tempAge;
    cout << "Enter student's name: \n";
    cin >> tempName;
    cout << "Enter student's id: \n";
    cin >> tempId;
    cout << "Enter student's gender <F-female/M-male>:  \n";
    cin >> tempGender;
    cout << "Enter student's age: \n";
    cin >> tempAge;
    
    Student* newStud = new Student(tempId);
    newStud->setAge(tempAge);
    newStud->setGender(tempGender);
    newStud->setName(tempName);
    
    if(checkIfStudentExistInMenu(newStud)){
        cout << "This student is already signed." << endl;
        return;
    }
    if (numAllStud > 0) {
        updateAllStudList();
    }
    else {
        allStudList = new Student*[++numAllStud];
    }
    allStudList[numAllStud - 1] = newStud;
    cout << "Student added." << endl;
}

void Menu::updateAllStudList(){
    Student** temp = new Student * [++numAllStud];
    assert(temp);
    for (int i = 0; i < numAllStud - 1; i++) {
        temp[i] = allStudList[i];
    }
    if (allStudList) {
 //       delete[] allStudList;
    }
    *allStudList = *temp;
}
void Menu::updateAllCourseList(){
    Course** temp = new Course *[++numAllCourses];
    for (int i = 0; i < numAllCourses - 1; i++) {
        temp[i] = allCoursesList[i];
    }
    if (allCoursesList){
  //      delete[] allCoursesList;
    }
    *allCoursesList = *temp;
}

bool Menu::checkIfStudentExistInMenu(Student *student){
    if(numAllStud>0){
        for (int i=0; i < numAllStud; i++){
            if(*allStudList[i] == *student){
                return true;
            }
        }
    }
    return false;
}

bool Menu::checkIfCourseExistInMenu(Course *course){
    if(numAllCourses>0){
        for (int i=0; i < numAllCourses; i++){
            if(*allCoursesList[i] == *course){
                return true;
            }
        }
    }
    return false;
}


void Menu::updateStudentAndCourse(Student student,Course course){
    if(numAllStud>0 && numAllCourses>0){
        for (int i=0; i < numAllStud; i++){
            if(*allStudList[i] == student){
                for(int j=0; j<numAllCourses; j++){
                    if(*allCoursesList[j] == course){
                        *allStudList[i] += *allCoursesList[j];
                        *allCoursesList[j] += *allStudList[i];
                        allCoursesList[j]->addGrade(-1);
                    }
                }
            }
        }
    }
}


void Menu::signingStudent(){
    int  courseID;
    string studentID;
    cout << "Enter Course's Number: \n";
    cin >> courseID;
    cout << "Enter student's id: \n";
    cin >> studentID;
    Student* tempStudent = new Student(studentID);
    Course* tempCourse = new Course(courseID);

    
    //If the course or the student exists in menu
    if(!checkIfCourseExistInMenu(tempCourse)){
        cout << "This Course doesn't exist." << endl;
        return;
    }
    if(!checkIfStudentExistInMenu(tempStudent)){
        cout << "This Student doesn't exist." << endl;
        return;
    }
        
    //If the course registered to the student course list or the student registered to the student list
    if(tempStudent->checkIfCourseRegisteredToStudent(*tempCourse) || tempCourse->checkIfStudentRegisteredToCourse(*tempStudent)){
        return;
    }
    updateStudentAndCourse(*tempStudent,*tempCourse);

}

void Menu::addGradeToStudent(){
    int  courseID;
    int grade;
    string studentID;
    cout << "Enter Course's Number: \n";
    cin >> courseID;
    cout << "Enter student's id: \n";
    cin >> studentID;
    cout << "Enter grade: \n";
    cin >> grade;
    Student* tempStudent = new Student(studentID);
    Course* tempCourse = new Course(courseID);
    
    //If the course or the student exists in menu
    if(!checkIfCourseExistInMenu(tempCourse)){
        cout << "This Course doesn't exist." << endl;
        return;
    }
    if(!checkIfStudentExistInMenu(tempStudent)){
        cout << "This Student doesn't exist." << endl;
        return;
    }
    //If the course registered to the student course list or the student registered to the student list
    if(!tempStudent->checkIfCourseRegisteredToStudent(*tempCourse) && !tempCourse->checkIfStudentRegisteredToCourse(*tempStudent)){
        for(int i=0; i<numAllCourses; i++){
            if(*tempCourse == *allCoursesList[i]){
                for(int j=0; j<numAllStud; j++){
                    if(*tempStudent == *allStudList[j]){
                        allCoursesList[i]->setNewGrade(j, grade);
                        cout<<"grade seted."<<endl;
                        return;

                    }
                }
            }
        }
    }

}

void Menu::printCourse(){
    int courseNum;
    cout << "Enter course's number: \n";
    cin >> courseNum;
    Course* tempCourse = new Course(courseNum);
    if(!checkIfCourseExistInMenu(tempCourse)){ //If course doesn't exist
        cout << "This Course doesn't exist." << endl;
        return;
    }
    if(numAllCourses>0){
        for(int i=0; i<numAllCourses; i++){
            if(*allCoursesList[i] == *tempCourse){ //check only if ID match
                cout << *allCoursesList[i] <<endl;
                return;
            }
        }
    }
}

void Menu::printStud(){
    string studId;
    cout << "Enter Studnet Id:  \n";
    cin >> studId;
    Student* tempStudent = new Student(studId);
    if(!checkIfStudentExistInMenu(tempStudent)){
        cout << "This Student doesn't exist." << endl;
        return;
    }
    if(numAllStud>0){
        for(int i=0; i<numAllStud; i++){
            if(*allStudList[i] == *tempStudent){ //check only if ID match
                cout << *allStudList[i] <<endl;
                return;
            }
        }
    }
}

