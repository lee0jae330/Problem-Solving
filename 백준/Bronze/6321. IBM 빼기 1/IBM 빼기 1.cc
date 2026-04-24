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
    while(T--){
        string s;
        cin >>s;
        cout <<"String #"<<num++<<'\n';
        for(int i=0;i<s.size();i++){
            if(s[i]=='Z')
                cout << 'A';
            else
                cout << (char)(s[i]+1);
        }
        
        cout <<"\n\n";
    }
    return 0;
}