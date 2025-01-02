#include "SimpleVector.h"
using namespace std;

int main(){
    SimpleVector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    cout<<"v(int vector): ";
    v.printData();
    v.pop_back();
    v.pop_back();
    cout<<v.size()<<" "<<v.capacity()<<endl;
    cout<<"v(int vector): ";
    v.printData();
    v.resize(20);
    cout<<"resized v: ";
    cout<<v.size()<<" "<<v.capacity()<<endl;
    
    SimpleVector<char> s(5);
    s.push_back('c');
    s.push_back('b');
    s.push_back('z');
    s.push_back('h');
    s.push_back('s');
    s.push_back('e');
    cout<<"s(char vector): ";
    s.printData();
    s.SortData();
    cout<<"sorted s: ";
    s.printData();
    cout<<s.size()<<" "<<s.capacity()<<endl;

    SimpleVector<char> dup(s);
    cout<<"dup(duplicated vector): ";
    dup.printData();
    cout<<dup.size()<<" "<<dup.capacity()<<endl;
    dup.pop_back();
    dup.pop_back();
    dup.pop_back();
    cout<<"updated dup(pop_back): ";
    dup.printData();
    cout<<dup.size()<<" "<<dup.capacity()<<endl;

    return 0;
}