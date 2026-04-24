#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
    int t,result=10000;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a<=b)
            result=min(result,b);
    }
    if(result==10000)
        cout<<-1;
    else
        cout<<result;
}