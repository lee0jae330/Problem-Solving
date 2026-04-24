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
        int x, y;
        cin >>x>>y;
        if(x>=y)
            cout <<"MMM BRAINS"<<'\n';
        else
            cout <<"NO BRAINS"<<'\n';
    }
    return 0;
}