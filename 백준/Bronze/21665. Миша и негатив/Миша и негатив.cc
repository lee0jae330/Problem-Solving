#include<iostream>
using namespace std;


char a[101][101], b[101][101];

int main(void){
    int n,m;
    cin >>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    //char tmp; cin >>tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>b[i][j];
    }
    int cnt=0;
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((a[i][j]=='B'&&b[i][j]=='W')||(a[i][j]=='W'&&b[i][j]=='B')){
                cnt++;
            }
        }
    }
    cout << n*m-cnt<<'\n';
}