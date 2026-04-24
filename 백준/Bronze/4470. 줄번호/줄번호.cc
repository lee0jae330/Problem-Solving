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
    int T,num=1;
    cin >>T;
    cin.ignore();
    while(T--){
        
        string s;
        getline(cin, s);
        cout <<num++<<". "<<s<<'\n';
    }
    return 0;
}