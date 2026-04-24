#include<iostream>
using namespace std;
int main(void){
    while(1){
        double N;
        cin >>N;
        if(!N)
            break;
        double r =0;
        r=1.+N+N*N+N*N*N+N*N*N*N;
        cout << fixed;
        cout.precision(2);
        cout << r<<'\n';
         
    }
}