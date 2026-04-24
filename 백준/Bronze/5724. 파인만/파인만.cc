#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

char arr[101][101];

int main(void){
    fastio();
    while(1){
        int N; cin >>N;
        if(!N)
            break;
        long long result=0;
        for(int i=1;i<=N;i++){
            result +=(N-i+1)*(N-i+1);
        }
        cout << result <<'\n';
    }
    return 0;
}