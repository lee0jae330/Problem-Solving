#include<iostream>
#include<string>
using namespace std;
int main(void){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int len=s.length();
        if(len>=6&&len<=9)
            cout<<"yes\n";
       else
           cout<<"no\n";
    }
    return 0;
}