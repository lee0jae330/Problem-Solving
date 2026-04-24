#include<bits/stdc++.h>

using namespace std;

int N,M,G,R;
int arr[51][51];
int visited[51][51];
char color[51][51];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int isFlower[51][51];
int sol;

vector<pair<int,int>>mud;
vector<int>comb;
queue<pair<int,int>>q;

void bfs(){
    int numOfflower=0;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        if(isFlower[x][y])
            continue;
        for(int i=0;i<4;i++){
            int tx = x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>=N||ty>=M)
                continue;
            if(!arr[tx][ty])
                continue;
            if(isFlower[tx][ty])
                continue;
            if(color[tx][ty]=='.'){
                color[tx][ty]=color[x][y];
                visited[tx][ty]=visited[x][y]+1;
                q.push({tx,ty});
            }
            else if(color[tx][ty]=='R'){
                if(color[x][y]=='G'&&visited[tx][ty]==visited[x][y]+1){
                    numOfflower++;
                    isFlower[tx][ty]=1;
                }
            }
            else{
                if(color[x][y]=='R'&&visited[tx][ty]==visited[x][y]+1){
                    numOfflower++;
                    isFlower[tx][ty]=1;
                }
            }
        }
    }
    sol=max(sol,numOfflower);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >>  G >> R;
    int canPlant=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                canPlant++;
                mud.push_back({i,j});
            }
        }
    }
    //comb  1:초록, 2:빨강, 0:빈칸
    for(int i=0;i<G;i++)
        comb.push_back(1);
    for(int i=0;i<R;i++)
        comb.push_back(2);
    for(int i=0;i<canPlant-G-R;i++)
        comb.push_back(0);
    sort(comb.begin(),comb.end());
    do{
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                color[i][j]='.';
        }
        memset(visited,0,sizeof(visited));
        memset(isFlower,0,sizeof(isFlower));
        for(int i=0;i<comb.size();i++){
            if(comb[i]){
                auto [x,y]=mud[i];
                visited[x][y]=1;
                q.push({x,y});
                if(comb[i]==1){
                    color[x][y]='G';
                }
                else{
                    color[x][y]='R';
                }
            }
        }
        bfs();
    }while(next_permutation(comb.begin(),comb.end()));
    cout << sol;
    return 0;
}