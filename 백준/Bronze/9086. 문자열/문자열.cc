#include<iostream>

#include<string>

using namespace std;

int main(void){
    int T; cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<s[0]<<s[s.size()-1]<<'\n';
    }
}