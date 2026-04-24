#include<iostream>
using namespace std;
int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);


    
    int N;
    cin>>N;
    switch(N){
            case 2:
            case 6:
            case 10:
            cout<<"Odd";
            break;
            case 4:
            case 8:
            cout<<"Even";
            break;
            default:
            cout<<"Either";
                
    }
}