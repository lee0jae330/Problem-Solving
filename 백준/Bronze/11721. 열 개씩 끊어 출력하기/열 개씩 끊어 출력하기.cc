#include<iostream>
#include<string>
using namespace std;


int main(void){
    string s;
    cin >>s; 
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(cnt==10){
            cout <<'\n';
            cnt=0;
        }
        cout<<s[i];
        cnt++;
            
    }
}