#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

char arr[101][101];

int main(void){
    fastio();
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >>arr[i][j];
    }
    int num; cin >>num;
    if(num==1)
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout <<arr[i][j];
            cout <<'\n';
        }
    else if(num==2){
        for(int i=0;i<N;i++){
            for(int j=N-1;j>=0;j--)
                cout <<arr[i][j];
            cout <<'\n';
        }
    }
    else{
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<N;j++)
                cout <<arr[i][j];
            cout <<'\n';
        }
    }
    return 0;
}