#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;

        int inner;
        if(a<=b) {
            inner = b - a;
        } else {
            inner = b - a +43;
        }
        int outer = 43 - inner;

        if(inner < outer) {
            cout << "Inner circle line" <<'\n';
        } else if (inner  > outer) {
            cout << "Outer circle line" <<'\n';
        } else {
            cout << "Same" <<'\n';
        }
    }

    return 0;
}