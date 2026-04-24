#include<iostream>

using namespace std;

int arr[101];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a, b,c;
        cin >>a>>b>>c;
        for(int x=a;x<=b;x++){
            arr[x]=c;
        }
    }
    for(int i=1;i<=N;i++)
        cout<<arr[i]<<' ';
    return 0;
    
}