#include<bits/stdc++.h>

using namespace std;

int arr[5][5][5];
int maze[5][5][5];
int visited[5][5][5];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

int zz[2]={-1,1};

vector<int>v={0,1,2,3,4};

int spin[5];

int sol = 123456789;

void bfs(int z, int x, int y){
    visited[z][x][y]=1;
    queue<tuple<int,int,int>>q;
    q.push({z,x,y});
    while(!q.empty()){
        tie(z,x,y)=q.front();
        q.pop();
        for(int i=0;i<2;i++){
            int tz=z+zz[i];
            if(tz<0||tz>=5||visited[tz][x][y])
                continue;
            if(maze[tz][x][y]){
                visited[tz][x][y]=visited[z][x][y]+1;
                q.push({tz,x,y});
            }
        }
        for(int i=0;i<4;i++){
            int tx=x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>=5||ty>=5||visited[z][tx][ty])
                continue;
            if(maze[z][tx][ty]){
                visited[z][tx][ty]=visited[z][x][y]+1;
                q.push({z,tx,ty});
            }
        }
    }
}


void turn(){
    int tmp[5][5];
    for(int n=0;n<5;n++){
       // cout << spin[n]<<'\n';
        for(int cnt=0;cnt<spin[n];cnt++){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++)
                    tmp[i][j]=maze[n][i][j];
            }
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    maze[n][j][4-i]=tmp[i][j];
                }
            }
        }    
    }
    /*for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++)
                cout << maze[i][j][k]<<' ';
            cout <<'\n';
        }
        cout <<'\n';cout <<'\n';
    }*/
    
    if(maze[0][0][0]&&maze[4][4][4]){
            bfs(0,0,0);
            if(visited[4][4][4]){
                sol=min(sol,visited[4][4][4]-1);
            }
            memset(visited,0,sizeof(visited));
        }
        if(maze[0][4][0]&&maze[4][0][4]){
            bfs(0,4,0);
            if(visited[4][0][4]){
                sol=min(sol,visited[4][0][4]-1);
            }
            memset(visited,0,sizeof(visited));
        }
        if(maze[0][0][4]&&maze[4][4][0]){
            bfs(0,0,4);
            if(visited[4][4][0]){
                sol=min(sol,visited[4][4][0]-1);
            }
            memset(visited,0,sizeof(visited));
        }
        if(maze[0][4][4]&&maze[4][0][0]){
            bfs(0,4,4);
            if(visited[4][0][0]){
                sol=min(sol,visited[4][0][0]-1);
            }
            memset(visited,0,sizeof(visited));
        }
}

void rec(int K){
    if(K==5){
        /*for(auto a: spin)
            cout << a<< ' ';
        cout <<'\n';*/
        turn();
        return;
    }
    for(int i=0;i<4;i++){
        spin[K]=i;
        rec(K+1);
    }

}




void select(){
    
    do{
        memset(visited,0,sizeof(visited));
        //판 선택하기
        for(int i=0;i<5;i++){
            int num = v[i];
            for(int r=0;r<5;r++){
                for(int c=0;c<5;c++){
                    maze[i][r][c]=arr[num][r][c];
                }
            }
        }
        rec(0); //회전시키기
        
        
        
    }while(next_permutation(v.begin(),v.end()));
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                cin >> arr[i][j][k];
                maze[i][j][k]=arr[i][j][k];
            }
                
        }
    }
    //rec(0); //회전시키기
        
    //spin[0]=3;
    //turn();
    select();

    
    if(sol==123456789)
        cout <<-1;
    else
        cout << sol;
    return 0;
}