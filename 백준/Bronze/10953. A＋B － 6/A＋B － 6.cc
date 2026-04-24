#include<iostream>


using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}



int main(void){
    fastio();
    int T;
    cin >>T;
    while(T--){
        int a, b;
        char c;
        cin >>a>>c>>b;
        cout << a+b<<'\n';
    }
    return 0;
}
