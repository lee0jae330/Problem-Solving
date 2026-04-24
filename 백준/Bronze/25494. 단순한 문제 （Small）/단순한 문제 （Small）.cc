#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

char arr[101][101];

int main(void){
    fastio();
    int T; cin >>T;
    while(T--){
        int a, b, c;
        cin >> a>>b>>c;
        int mn =min(a,b);
        mn =min(mn,c);
        cout << mn <<'\n';
    }
    return 0;
}
