#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string str;
    cin >> N >> str;
    
    map<char,int>m;

  

    for(char c: str) {
        if(c !='H' && c!='I' && c!='A' && c!='R' && c!='C') {
            continue;
        }
        
        if(m.find(c) == m.end()) {
            m[c] = 1;
        } else {
            m[c]++;
        }
    }

    int mn = 100001;

    if(m.size() != 5) {
        cout << 0 << '\n';
        return 0;
    }

    for(auto iter = m.begin() ;iter!=m.end();iter++) {
        mn = min(iter->second, mn);
    } 

    if(mn == 100001) {
        cout << 0 <<'\n';
        return 0;
    }

    cout << mn <<'\n';
    return 0;
}