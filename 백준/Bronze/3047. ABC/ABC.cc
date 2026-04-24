#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    vector<int>v(3);
    cin >>v[0]>>v[1]>>v[2];
    sort(v.begin(), v.end());
    string s;
    cin >>s;
    if(s[0]=='A'){
        cout <<v[0]<<' ';
    }    
    else if(s[0]=='B'){
        cout <<v[1]<<' ';
    }
    else{
        cout <<v[2]<<' ';
    }
     if(s[1]=='A'){
        cout <<v[0]<<' ';
    }    
    else if(s[1]=='B'){
        cout <<v[1]<<' ';
    }
    else{
        cout <<v[2]<<' ';
    }
     if(s[2]=='A'){
        cout <<v[0]<<' ';
    }    
    else if(s[2]=='B'){
        cout <<v[1]<<' ';
    }
    else{
        cout <<v[2]<<' ';
    }
}