#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int N, L,R;
int arr[101][101], visited[101][101];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

vector<int> country;
vector<pair<int,int>>area;

void bfs(int x, int y){
    queue<pair<int,int>>q;
    country.push_back(arr[x][y]);
    area.push_back({x,y});
    q.push({x,y});
    visited[x][y]=1;
    while(!q.empty()){
        x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx = x+xx[i], ty= y+yy[i];
            
            if(tx>=0&&ty>=0&&tx<N&&ty<N&&!visited[tx][ty]){
                int gap = abs(arr[x][y]-arr[tx][ty]);
                if(gap>=L&&gap<=R){ //차이가 기준을 맞춘다면
                    visited[tx][ty]=1;
                    country.push_back(arr[tx][ty]);
                    area.push_back({tx,ty});
                    q.push({tx,ty});
                }
            }
        }
    }
}

int main(){
    fastio();
    cin >>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >>arr[i][j];
        }
    }
    int flag=0, day=0;
    while(1){
        flag=0;
        country.clear();
        area.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                visited[i][j]=0;
            
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                country.clear();
                area.clear();
                if(!visited[i][j]){
                     bfs(i,j);
                    if(country.size()>1){
                        flag=1;
                        int sum=0;
                        for(auto num:country){
                            sum+=num;
                        }
                        int sz= country.size();
                        sum /= sz;
                        for(int i=0;i<sz;i++){
                            arr[area[i].first][area[i].second]=sum;
                        }
                    }
                }
            }
        }
        
        if(!flag)
            break;
        else
            day++;
    }
   cout << day<<'\n';
   return 0;
}