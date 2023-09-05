#include <iostream>
using namespace std;

//check if Symmetric Ex1
template <class T>
bool Symmetric(T* arr,int size){
    int j = size -1;
    for (int i = 0; i<size; i++) {
        if (arr[i] != arr[j]) {
            return false;
        }
        if (i == j) {
            return true;
        }
        j--;
    }
    return true;
}
//shift right Ex2
template <class T>
T* ShiftRight(T* arr ,int size,int n) {
    int newSize = size - (n%size);
    int i=0,j = n%size;
    T* tempArr = new T[size];
    for ( i = 0; i < size; i++) {
        if (newSize != size) {
            tempArr[i] = arr[newSize];
            newSize++;
        }
      
    }
    for (i=0; i<newSize; i++) {
        tempArr[j] = arr[i];
        j++;
    }
    return tempArr;
}

template<class T>
void printArr(T* arr,int size){
    for (int i = 0 ; i <size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    //ex1
    int intArray[] = {1,2,3,2,1};
    char charArray[] = {'a', 'b', 'c', 'x', 'a'};
    if(Symmetric(intArray,5)){
        cout<<"Symmetric"<<endl;
    }
    else{
        cout<<"Not Symmetric"<<endl;
    }
    if(Symmetric(charArray,5)){
        cout<<"Symmetric"<<endl;
    }
    else{
        cout<<"Not Symmetric"<<endl;
    }
    //ex2
    int shift[] ={1, 2, 3, 4, 5};
    printArr(ShiftRight(shift, 5, 2), 5);
    return 0;
}

