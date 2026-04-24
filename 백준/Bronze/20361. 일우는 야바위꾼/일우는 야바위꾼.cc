#include<iostream>
#include<algorithm>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[200001];

int main(void){
    fastio();
    int N, X,K;
    cin >> N>>X>>K;
    arr[X]=1;
    while(K--){
        int a, b; cin >>a>>b;
        swap(arr[a],arr[b]);
    }
    for(int i=1;i<=N;i++){
        if(arr[i])
            cout <<i;
    }
    return 0;
}
