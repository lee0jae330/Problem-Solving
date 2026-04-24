#include<bits/stdc++.h>

using namespace std;

int N;
int arr[101][101];
int xx[4]={1,0,-1,0};
int yy[4]={0,-1,0,1};

vector<int>v;

void rec(int gen, int n){
    if(n==gen)
        return;
    int sz = v.size();
    for(int i=sz-1;i>=0;i--){
        int dir = v[i]+1;
        if(dir==4)
            dir=0;
        v.push_back(dir);
    }
    rec(gen,n+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while(N--){
        v.clear();
        int x,y,d,g;
        cin >> x >> y >> d >>g;
        v.push_back(d);
        arr[x][y]=1;
        rec(g,0); //회전방향구하기
        for(int i=0;i<v.size();i++){
            int tx = x+xx[v[i]],ty=y+yy[v[i]];
            if(tx>=0&&ty>=0&&tx<101&&ty<101)
                arr[tx][ty]=1;
            x=tx,y=ty;
        }
        
    }
    int sol=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j]&&arr[i+1][j]&&arr[i][j+1]&&arr[i+1][j+1])
                sol++;
        }
    }
    cout << sol;
    return 0;
}