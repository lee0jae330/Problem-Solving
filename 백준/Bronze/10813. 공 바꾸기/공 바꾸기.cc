#include<iostream>
#include<algorithm>

using namespace std;

int arr[101];

int main(){
    for(int i=0;i<101;i++)
        arr[i]=i;
    int N, M;
    cin >> N >> M;
    for(int x=0;x<M;x++){
        int i,j;
        cin>> i>>j;
        swap(arr[i],arr[j]);
    }
    for(int i=1;i<=N;i++)
        cout<< arr[i]<<' ';
    return 0;
}