#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(void){
    fastio();
    int T;
    cin >>T;
    while(T--){
        int  N,M;
        cin >>N>>M;
        if(N<12||M<4)
            cout<<-1<<'\n';
        else{
            cout << M*11+4<<'\n';
        }
    }
    return 0;
}