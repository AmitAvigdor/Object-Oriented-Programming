#ifndef Array_hpp
#define Array_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class Array {
    T* arr;
    int size;
public:
    Array(T* arr = NULL ,int size = 0) :arr(arr),size(size) {}
    int findIndex(T) throw (const T);
    T findMax();
    T findMin();
    T operator[](int) throw (int);
    T inputFromUser();
    Array<T>& operator += (T newT);
    Array<T>& operator -= (T newT);
    Array<T>& operator + (Array newArrT);
    bool operator == (Array)throw (char*);
    void operator << (Array);
    T* getArr(){return arr;}
    int getSize(){return size;}
    bool isSorted();
    void printType(string);

};

//finding index
template <class T>
int Array<T>::findIndex(T val) throw(const T){
    for(int i = 0; i < size; i++){
        if(arr[i]!=val && i==(size-1)){
            throw val;
        }
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}
//find max
template <class T>
T Array<T>::findMax() {
    if(arr == NULL){
        return NULL;
    }
    T max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
        return max;
}
//find min
template <class T>
T Array<T>::findMin() {
    if(arr == NULL){
        return NULL;
    }
    T min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
        return min;
}

//getting input from user
template <class T>
T Array<T>::inputFromUser() {
    T userInput;
    cout<<"Enter Value: "<<endl;
    cin>>userInput;
        return userInput;
}

//operator []
template <class T>
T Array<T>::operator[](int Tindex) throw(int){

    if (Tindex < 0 ) {
        throw Tindex;
    }
    if(Tindex >= this->size){
        throw Tindex;
    }
    return arr[Tindex];
}

//operator +=
template <class T>
Array<T>& Array<T>::operator += (T newT) {
    T* TempArr = new T[++size];
    TempArr[0]=newT;
    int i,j=0;
    for(i = 1;i<=size;i++){
        TempArr[i]=arr[j];
        j++;
    }
    arr = TempArr;
    return *this;
}

//operator -=
template <class T>
Array<T>& Array<T>::operator -= (const T newT) {
    int newSize = 0,j = 0;
    for (int i = 0; i<size; i++) {
        if(arr[i] != newT){
            newSize++;
        }
    }
    T* tempArr=new T[newSize];
    for (int i = 0; i<size; i++) {
        if (arr[i] != newT) {
            tempArr[j]=arr[i];
            j++;
        }
    }
    size = newSize;
    arr = tempArr;
    return *this;
}

//opertaor ==
template <class T>
bool Array<T>::operator == (Array other) throw (char*){

    if (other.getArr() == NULL || this->arr == NULL) {
        throw "Empty Array!";
    }
    if (other.getSize() != this->size) {
        return false;
    }
    for (int i = 0; i<size; i++) {
        if (arr[i] != other.getArr()[i]) {
           return false;
        }
    }
    return true;
}

//check if the array is sorted
template <class T>
bool Array<T>::isSorted() {
    for (int i = 0; i<size-1; i++) {
        if(arr[i]>arr[i+1]){
            cout<<"The Array Is Not Sorted!"<<endl;
            return false;
        }
    }
    cout<<"The Array Is Sorted!"<<endl;
    return true;
}

//operator <<
template <class T>
void Array<T>::operator << (Array object) {
    for (int i = 0 ; i <size; i++) {
        cout <<object.arr[i]<<" ";
    }
    cout<<"\nThe Size is: "<< object.size<<endl;
}

//print the type
template <class T>
void Array<T>::printType(string type) {
    cout<<"The Type is: "<<type<<endl;
}

//operator +
template <class T>
Array<T>& Array<T>::operator + (Array newArrT) {
    int sizeArrT = newArrT.getSize() + size;
    T* TempArr = new T[sizeArrT];
    int i;
    for(i = 0;i<=size;i++){
        TempArr[i]=arr[i];
    
    }
    for (int j = 0; j<newArrT.getSize(); j++) {
        TempArr[i]=newArrT[j];
        i++;
    }
    Array newArray = new Array(TempArr,sizeArrT);
    return newArray;
}

#endif /* Array_hpp */
