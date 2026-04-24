#include<iostream>
#include<string>
using namespace std;


int main(void){
    int T;
    cin >>T;
    while(T--){
        string s;
        cin >>s;
        int result=0;
        if(s[0]=='U'){
            result=1;
            for(int i=1;i<s.size();i++){
                if(s[i]=='D')
                    break;
                result++;
            }
        }
        cout << result<<'\n';
    }
}