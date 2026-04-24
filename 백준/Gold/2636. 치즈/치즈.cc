#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int cheese[101][101];
int visited[101][101];
int N,M;
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};
int isChange[101][101];

void isOutside(int x, int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    while(!q.empty()){
        x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+xx[i],ty=y+yy[i];
            
            if(tx<0||ty<0||tx>=N||ty>=M)
                continue;
            if(cheese[tx][ty]) //공기의 옆이 치즈라면 녹이기
                isChange[tx][ty]=1;
            if(!cheese[tx][ty]&&!visited[tx][ty]){
                visited[tx][ty]=1;
                q.push({tx,ty});
                
            }
        
           
        }
    }
}

void isMelt(int x, int y){
    if(isChange[x][y])
        cheese[x][y]=0;
}


int main(){
    //fastio();
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            cin >>cheese[i][j];
    }
    int flag=0, t=0, cnt=0;
    while(1){
        int tmp=0;
       
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(cheese[i][j]==1)
                    tmp++;
            }
        }
        if(!tmp){
            break;
        }
        else
            cnt=tmp;
        memset(visited,0,sizeof(visited));
        //1. 공기찾기 + 맞닿은 치즈찾기
        isOutside(0,0);  
        //2. 녹이기
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(cheese[i][j]==1)
                    isMelt(i,j);
            }
        }
        t++;
    }
    
    cout << t <<'\n'<<cnt <<'\n';\
    
}