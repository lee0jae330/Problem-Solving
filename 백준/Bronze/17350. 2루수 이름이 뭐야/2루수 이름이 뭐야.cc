#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(void){
    fastio();
    int N, flag=0;
    cin >>N;
    while(N--){
        string s;
        cin >>s;
        if(s=="anj")
            flag=1;
    }    
    if(flag)
        cout <<"뭐야;";
    else
        cout <<"뭐야?";
    
}