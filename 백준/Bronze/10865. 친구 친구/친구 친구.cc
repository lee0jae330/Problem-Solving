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

int arr[100001];

int main(void){
    int N, M;
    fastio();
    cin >>N>>M;
    for(int i=0;i<M;i++){
        int x, y; cin>>x>>y;
        arr[x]++;
        arr[y]++;
    }
    for(int i=1;i<=N;i++)
        cout << arr[i]<<'\n';
    return 0;
}