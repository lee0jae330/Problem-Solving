#include<bits/stdc++.h>

using namespace std;

char arr[3073][6144];

void rec(int N, int r, int c){
    if(N==3){
        arr[r][c+2]='*';
        arr[r+1][c+1]='*';
        arr[r+1][c+3]='*';
        for(int i=0;i<5;i++)
            arr[r+2][c+i]='*';
        return;
    }
    rec(N/2,r,c+N/2);
    rec(N/2,r+N/2,c);
    rec(N/2,r+N/2,c+N);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<2*N-1;j++)
            arr[i][j]=' ';
    }
    rec(N,0,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<2*N-1;j++)
            cout << arr[i][j];
        cout <<'\n';
    }
}