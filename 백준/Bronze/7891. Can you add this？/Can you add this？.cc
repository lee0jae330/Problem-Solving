#include<iostream>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
   int n;cin>>n;
    while(n--){
        int a,b; cin>>a>>b;
        cout <<a+b<<'\n';
    }
}