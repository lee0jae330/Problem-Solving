#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        string s;
        getline(cin,s);
        
        if(!s.compare("END"))
            break;
        reverse(s.begin(),s.end());
        cout<<s<<'\n';
    }
    return 0;
}
