#include<bits/stdc++.h>

using namespace std;

int N, W, L;
int truck[1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> W >> L;
    for(int i=0;i<N;i++)
        cin >> truck[i];
    int num=0,now=0,t=0,idx=0;
    queue<pair<int,int>>q;
    while(N>num){
        t++;
        if(!q.empty()){
            if(q.front().second+W==t){
                now-=q.front().first;
                //cout << "pop "<<q.front().first<<' '<<t<<' '<<now<<'\n';
                q.pop();
                num++;
            }
        }
        if(now+truck[idx]<=L){
            now+=truck[idx];
            q.push({truck[idx],t});
            //cout << "push "<<truck[idx]<<' '<<t <<' '<<now<<'\n';
            idx++;
        }
        
    }
    cout << t;
    return 0;
}