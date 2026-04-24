#include<bits/stdc++.h>

using namespace std;

const int MX = 1e6+1;

char dat[MX];
int nxt[MX],pre[MX];
int unused = 1;

void init(){
    fill(nxt, nxt+MX, -1);
    fill(pre, pre+MX, -1);
    unused=1;
}

void traverse(){
    int cur = nxt[0];
    while(cur!=-1){
        cout << dat[cur];
        cur=nxt[cur];
    }
}

void insert(int addr, char c){
    dat[unused]=c;
    pre[unused]=addr;
    nxt[unused]=nxt[addr];
    if(nxt[addr]!=-1)
        pre[nxt[addr]]=unused;
    nxt[addr]=unused;
    unused++;
}

void erase(int addr){
    int n=nxt[addr], p=pre[addr];
    nxt[p]=n;
    if(n!=-1)
        pre[n]=p;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        init();
        int cursor = 0;
        string s;
        cin >> s;
        for(auto c : s){
            if(c=='-'){
                if(pre[cursor]!=-1){
                    erase(cursor);
                    cursor=pre[cursor];
                }
            }
            else if(c=='<'){
                if(pre[cursor]!=-1)
                    cursor=pre[cursor];
            }
            else if(c=='>'){
                if(nxt[cursor]!=-1)
                    cursor=nxt[cursor];
            }
            else{
                insert(cursor, c);
                cursor=nxt[cursor];
            }
        }
        traverse();
        cout << '\n';
        
    }
    return 0;
}