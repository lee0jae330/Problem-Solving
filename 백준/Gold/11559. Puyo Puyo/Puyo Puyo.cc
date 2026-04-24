#include<bits/stdc++.h>

using namespace std;

char arr[12][6];
char cp[12][6];

int visited[12][6];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int flag=1;

void fall(){
    for(int c=0;c<6;c++){
        for(int r=11;r>=0;r--){
            if(arr[r][c]!='.'){
                for(int i=r+1;i<12;i++){
                    if(arr[i][c]=='.'){
                        swap(arr[i-1][c],arr[i][c]);
                    }
                    else
                        break;
                }
            }
        }
    }
}

void bfs(int x, int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    int cnt=1;
    while(!q.empty()){
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx = x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>=12||ty>=6)
                continue;
            if(arr[tx][ty]=='.')
                continue;
            if(visited[tx][ty])
                continue;
           if(arr[tx][ty]==arr[x][y]){
            visited[tx][ty]=1;
            cnt++;
            q.push({tx,ty});   
           }
            
        }
    }
    if(cnt>=4){
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(visited[i][j]){
                    arr[i][j]='.';
                }
            }
        }
        flag=1;
    }

    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++)
            cin >> arr[i][j];    
    }
    int sol=0;
    while(1){
        if(!flag)
            break;
        flag=0;
        
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(!visited[i][j]&&arr[i][j]!='.'){
                    bfs(i,j);
                    memset(visited,0,sizeof(visited));
                }
            }
        }
        if(flag){
            fall();
            sol++;
        }
       
    }
    cout <<sol<<'\n';
    return 0;
}