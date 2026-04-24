#include<iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    long long result=0;
    for(int i=1;i<=N;i++)
        result+=i*i*i;
    cout << result<<'\n';
    return 0;
}