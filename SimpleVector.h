#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
class SimpleVector{
private:
    T* data;
    int currentSize;
    int currentCapacity;
public:
    void resize(int newCapacity){
        if(newCapacity>currentCapacity){
            T* temp=new T[newCapacity]; //resized array
            memcpy(temp,data,currentSize*sizeof(T)); //copy
            delete[] data; //delete original array
            data=temp;
            currentCapacity=newCapacity;
        }
    }
    SimpleVector(int capacity=10){
        data=new T[capacity];
        currentSize=0;
        currentCapacity=capacity;
    }
    SimpleVector(const SimpleVector& other){
        this->data=new T[other.size()];
        this->currentCapacity=other.capacity();
        this->currentSize=other.size();
        memcpy(this->data,other.data,other.size()*sizeof(T));
    }
    ~SimpleVector(){ 
        delete[] data;
        _CrtDumpMemoryLeaks(); //check memory leaks
    }
    void push_back(const T& value){
        if(currentSize==currentCapacity){ //Full
            resize(currentCapacity+5);
        }
        data[currentSize++]=value;
    }
    void pop_back(){
        if(currentSize>0){
            data[--currentSize]=T(); //default value(delete original value)
        }
    }
    int size() const {
        return currentSize;
    }
    int capacity() const {
        return currentCapacity;
    }
    void printData(){
        cout<<"{ ";
        for(int i=0;i<currentSize;i++){
            cout<<data[i]<<" ";
        }
        cout<<"}"<<endl;
    }
    void SortData(){
        sort(data,data+currentSize);
    }
};