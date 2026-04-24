#include<iostream>
#include<string>
using namespace std;
string s[11];
int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
       cin >> s[i];
    }
    for(int i=0;i<n;i++){

        for(int j=m-1;j>=0;j--)

            cout<<s[i][j];
        cout<<'\n';

    }
}