#include<iostream>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int a[101][101],b[101][101];
int main(void){
    fastio();
    int N,M; cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >>a[i][j];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>b[i][j];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            cout<<a[i][j]+b[i][j];
            if(j==M-1)
                cout<<'\n';
            else
                cout<<' ';
        }
    
}