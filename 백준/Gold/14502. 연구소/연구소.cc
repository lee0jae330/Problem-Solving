#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[9][9];
int field[9][9];
int visited[9][9];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

vector<pair<int,int>>emp;
vector<int>comb;

int sol=-1;

void bfs(int x, int y){
    visited[x][y]=1;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>=N||ty>=M||visited[tx][ty])
                continue;
            if(field[tx][ty]!=1){
                visited[tx][ty]=1;
                q.push({tx,ty});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            if(!arr[i][j])
                emp.push_back({i,j});
        }
    }
    for(int i=0;i<3;i++)
        comb.push_back(0);
    for(int i=0;i<emp.size()-3;i++)
        comb.push_back(1);
    do{
        //field에서 벽을 새로 만들거임
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                field[i][j]=arr[i][j];
        }
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<comb.size();i++){
            if(!comb[i]){
                auto [x,y]=emp[i];
                field[x][y]=1;
            }
        }
        //벽을 새로 새움 
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j]&&field[i][j]==2){
                    bfs(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!field[i][j]&&!visited[i][j])
                    cnt++;
            }
        }
        sol =max(sol,cnt);
        
    }while(next_permutation(comb.begin(),comb.end()));
    cout << sol <<'\n';
    return 0;
}