#include<bits/stdc++.h>

using namespace std;

int N,M,fuel,tx,ty;
int INF = INT_MAX;
int arr[21][21];
int dist[21][21];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

queue<pair<int,int>>q;
pair<int,int>p[21][21];

void init(int x){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++)
            dist[i][j]=-1;
    }
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first, y= q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+xx[i], ny=y+yy[i];
            if(nx<0||ny<0||nx>=N||ny>=N)
                continue;
            if(arr[nx][ny]!=1&&dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
        
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> fuel;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    }
    cin >> tx >> ty;
    tx--,ty--;
    for(int i=0;i<M;i++){
        int px, py, dx,dy;
        cin >> px>>py>>dx>>dy;
        px--;py--;dx--;dy--;
        arr[px][py]=2;
        p[px][py]={dx,dy};
    }

    int ifAllpassGone=0;
    while(1){
        init(N);
        q.push({tx,ty});
        dist[tx][ty]=0;
        bfs();
        int flag=0;
        int min_dist = INF;
        int px,py;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arr[i][j]==2&&dist[i][j]!=-1){
                    if(min_dist>dist[i][j]){
                        px=i, py=j;
                        min_dist=dist[i][j];
                        flag=1;
                    }
                }
            }
        }
        if(!flag)
            break;
        if(min_dist>=fuel)
            break;
        
        else
            fuel-=min_dist;
        
        
        init(N);
        tx=px, ty=py;
        arr[tx][ty]=0;
        q.push({tx,ty});
        dist[tx][ty]=0;
        bfs();
        
        
        int dx=p[tx][ty].first, dy = p[tx][ty].second;
        if(dist[dx][dy]==-1)
            break;
        if(dist[dx][dy]>fuel)
            break;
        
        else{
            fuel-=dist[dx][dy];
            fuel+=dist[dx][dy]*2;
        }
        tx=dx, ty=dy;
        flag=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arr[i][j]==2)
                    flag=1;
            }
        }
        if(!flag){
            ifAllpassGone=1;
            break;
        }
            
    }
    if(ifAllpassGone)
        cout << fuel<<'\n';
    
    else
        cout << -1<<'\n';
    return 0;
}