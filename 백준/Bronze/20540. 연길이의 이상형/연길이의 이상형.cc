#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(void){
    string s;
    cin >>s;
    if(s[0]=='I')
        cout << 'E';
    else
        cout <<'I';
    if(s[1]=='N')
        cout << 'S';
    else
        cout <<'N';
    if(s[2]=='T')
        cout << 'F';
    else
        cout <<'T';
    if(s[3]=='P')
        cout << 'J';
    else
        cout <<'P';
    return 0;
}