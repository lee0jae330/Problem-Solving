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
    char s[101];
    int cnt =0;
    while(cin.getline(s,100)){
        cnt++;
    }
    cout <<cnt;
    return 0;
}