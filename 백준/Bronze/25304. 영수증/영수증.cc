#include<iostream>
using namespace std;
int main(void){
    long long x,result=0,t; cin>>x>>t;
    while(t--){
        long long a,b; cin>>a>>b;
        result+=a*b;
    }
    if(result==x)
        cout<<"Yes";
    else
        cout<<"No";
}