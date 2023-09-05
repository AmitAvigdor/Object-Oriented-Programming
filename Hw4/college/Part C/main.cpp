#include <iostream>
#include "Array.hpp"
using namespace std;



int main() {

    
    //all arrays
    float firstFloat[] = {1.7,0.4,6.1,8.6,3.8,1.9};
    float secFloat[] = {7.2,0.3,3.1,8.6,9.8,1.2};
    int firstInt[] ={1,2,3,6,8};
    int secInt[] ={5,2,3,1,4};
    
    //all Array Classes
    Array<float> firstArr(firstFloat,6);
    Array<float> secArr(secFloat,6);
    Array<int> thirdArr(firstInt,5);
    Array<int> forthArr(secInt,5);
    
    
    //find index
    //first array
    try {
        cout<<"----------------------"<<endl;
        cout<<"Finding Index Function"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"First Float Array"<<endl;
        float index = firstArr.findIndex(firstArr.inputFromUser());
        cout<<index<<endl;
    }
    catch (float wrongValue) {
        cout<<"Invaild Value: "<<wrongValue<<endl;}
    
    //second array
    try{
        cout<<"Second Float Array"<<endl;
        float indexsec = secArr.findIndex(secArr.inputFromUser());
        cout<<indexsec<<endl;
    }
    catch (float wrongValue) {
        cout<<"Invaild Value: "<<wrongValue<<endl;}
    
    //third array
    try{
        cout<<"First int Array"<<endl;
        int indexfirst = thirdArr.findIndex(thirdArr.inputFromUser());
        cout<<indexfirst<<endl;
    }
    catch (int wrongValue) {
        cout<<"Invaild Value: "<<wrongValue<<endl;}
    
    //forth array
    try{
        cout<<"Second int Array"<<endl;
        int indexThird = forthArr.findIndex(forthArr.inputFromUser());
        cout<<indexThird<<endl;
    }
    catch (int wrongValue) {
        cout<<"Invaild Value: "<<wrongValue<<endl;}

    //operator []
    //first array
    try {
        cout<<"----------------------"<<endl;
        cout<<"operator [] "<<endl;
        cout<<"----------------------"<<endl;
        cout<<"First Float Array"<<endl;
        float lookIndex = firstArr[firstArr.inputFromUser()];
        cout<<lookIndex<<endl;
    } catch (int i) {
        cout<<"The index "<<i<<" is not there"<<endl;
    }
    //second array
    try{
        cout<<"Second Float Array"<<endl;
        float lookIndexone = secArr[secArr.inputFromUser()];
        cout<<lookIndexone<<endl;
    } catch (int i) {
        cout<<"The index "<<i<<" is not there"<<endl;
    }
    //third array
    try{
        cout<<"First int Array"<<endl;
        float lookIndextwo = thirdArr[thirdArr.inputFromUser()];
        cout<<lookIndextwo<<endl;
    } catch (int i) {
        cout<<"The index "<<i<<" is not there"<<endl;
    }
    //forth array
    try{
        cout<<"Second int Array"<<endl;
        float lookIndexthree = forthArr[forthArr.inputFromUser()];
        cout<<lookIndexthree<<endl;
    } catch (int i) {
        cout<<"The index "<<i<<" is not there"<<endl;
    }
    
    
    //operator ==
    try {
        if (firstArr == secArr) {
            cout<<"equal"<<endl;
        }
    }catch (char* message) {
        cout<<message<<endl;
    }
    
    
//get value from user and delete from array
    cout<<"--------------------------"<<endl;
    cout<<"Delete From Array Function"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"First Float Array"<<endl;
    firstArr -= firstArr.inputFromUser();
    for (int i = 0; i<firstArr.getSize(); i++) {
        cout<<firstArr.getArr()[i]<<" ";
    }
    cout<<endl;
    cout<<"Second Float Array"<<endl;
    secArr -= secArr.inputFromUser();
    for (int i = 0; i<secArr.getSize(); i++) {
        cout<<secArr.getArr()[i]<<" ";
    }
    cout<<endl;
    cout<<"First int Array"<<endl;
    thirdArr -= thirdArr.inputFromUser();
    for (int i = 0; i<thirdArr.getSize(); i++) {
        cout<<thirdArr.getArr()[i]<<" ";
    }
    cout<<endl;
    cout<<"Second int Array"<<endl;
    forthArr -= forthArr.inputFromUser();
    for (int i = 0; i<forthArr.getSize(); i++) {
        cout<<forthArr.getArr()[i]<<" ";
    }

//get value from user and insert in the start
    cout<<"\n-------------------------------"<<endl;
    cout<<"Insert In The Start Function"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"First Float Array"<<endl;
    firstArr += firstArr.inputFromUser();
    for (int i = 0; i<firstArr.getSize(); i++) {
        cout<<firstArr.getArr()[i]<<" ";
    }
    cout<<endl;
    cout<<"Second Float Array"<<endl;
    secArr += secArr.inputFromUser();
    for (int i = 0; i<secArr.getSize(); i++) {
        cout<<secArr.getArr()[i]<<" ";
    }
    cout<<endl;
    cout<<"First int Array"<<endl;
    thirdArr += thirdArr.inputFromUser();
    for (int i = 0; i<thirdArr.getSize(); i++) {
        cout<<thirdArr.getArr()[i]<<" ";
    }
    cout<<endl;
    cout<<"Second Float Array"<<endl;
    forthArr += forthArr.inputFromUser();
    for (int i = 0; i<forthArr.getSize(); i++) {
        cout<<forthArr.getArr()[i]<<" ";
    }
    
    
    //check if array is sorted
    cout<<"\n---------------------------------------"<<endl;
    cout<<"Check If The Array Is Sorted Function"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"First Float Array"<<endl;
    if (firstArr.isSorted()) {
        cout<<endl;
    }
    cout<<"Second Float Array"<<endl;
    if (secArr.isSorted()) {
        cout<<endl;
    }
    cout<<"First int Array"<<endl;
    if (thirdArr.isSorted()) {
        cout<<endl;
    }
    cout<<"Second int Array"<<endl;
    if (forthArr.isSorted()) {
        cout<<endl;
    }
    
    
    return 0;
}
