#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(void){
    while(1){
        string s;   getline(cin, s);
        if(s=="***")
            break;
        for(int i=s.size()-1;i>=0;i--)
            cout<<s[i];
        cout <<'\n';
        
    }
}