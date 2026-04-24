#include<bits/stdc++.h>

using namespace std;

char arr[6562][6562];

void rec(int N,int r, int c,int cnt){
    //cout << N << ' '<<r<<' '<<c<<' '<<cnt<<'\n';
    if(cnt==5)
        return;
    if(N==1){
        arr[r][c]='*';
        return;
    }
    int num=1;
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            rec(N/3,r+N/3*x,c+N/3*y,num);
            num++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            arr[i][j]=' ';
    }
    rec(N,0,0,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << arr[i][j];
        cout <<'\n';
    }
    return 0;
}