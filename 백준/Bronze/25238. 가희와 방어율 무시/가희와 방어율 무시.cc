#include<iostream>
using namespace std;
int main(void){
    double a,b,r; cin >>a >> b;
    r=a*(100.-b)/100;
    if(100.<=r)
        cout<<0;
    else
        cout<<1;
    return 0;
}