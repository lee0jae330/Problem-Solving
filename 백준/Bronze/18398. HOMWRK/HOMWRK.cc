#include<iostream>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(void){
    fastio();
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        while(N--){
            int a,b;
            cin>>a>>b;
            cout<<a+b<<' '<<a*b<<'\n';
        }
    }
}