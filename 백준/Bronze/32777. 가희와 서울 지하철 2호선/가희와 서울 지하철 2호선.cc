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

        int inner = 0, outer = 0;

        int i = a;
        while(i!=b) {
            i++;
            if(i > 243) {
                i = 201;
            }
            inner++;
        }

        i = a;
        while(i!=b) {
            i--;
            if(i < 201) {
                i =243;
            }
            outer++;
        }

        if(inner < outer) {
            cout << "Inner circle line"<<'\n';            
        } else if(inner>outer) {
            cout << "Outer circle line"<<'\n';
        } else {
            cout << "Same" << '\n';
        }
    }

    return 0;
}