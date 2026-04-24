#include<iostream>
#include<string>
using namespace std;
int main(void){
    string s1,s2;
    cin >>s1>>s2;
    if(s1.length()<s2.length())
        cout<<"no";
    else
        cout <<"go";
    return 0;
}