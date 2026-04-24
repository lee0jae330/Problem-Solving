#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(void){
    vector<int>v;
    for(int i=1;i<=5;i++){
        string s; cin >>s;
        int f=0;
        for(int j=0;j<s.size()-2;j++){
            if(s[j]=='F'){
                if(s[j+1]=='B'&&s[j+2]=='I'){
                    v.push_back(i);
                    f=1;
                }
            }
            if(f)
                break;
        }
    }
    if(v.size()){
        for(int i=0;i<v.size();i++)
            cout << v[i]<<' ';
    }
    else
    cout <<"HE GOT AWAY!";
}