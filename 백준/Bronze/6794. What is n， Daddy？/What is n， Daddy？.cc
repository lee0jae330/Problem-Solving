#include<iostream>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int N,cnt=0;
    cin>> N;
    if(N<6)
    cout<<N/2+1;
    else{
        switch(N){
                case 6:
                cout<<3;
                break;
                case 7:
                case 8:
                cout<<2;
                break;
                default:
                cout<<1;
                   
        }
    }

}