#include<bits/stdc++.h>

using namespace std;

int N,Q;

int arr[65][65];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int visited[65][65];

void spin(int level){
    int num = pow(2,N);
    int l = pow(2,level);
    if(l==1)
        return;
    int cp[65][65]={0,};
    
    for(int r=0;r<num/l;r++){
        for(int c=0;c<num/l;c++){
            int x= l*r, y= l*c;
            for(int cnt=0;cnt<l/2;cnt++){
                int tx= x+cnt,ty=y+cnt;
                int side = l-2*cnt;

                for(int i=0;i<side;i++){
                    cp[tx+i][ty+side-1]=arr[tx][ty+i];
                    cp[tx+side-1][ty+side-1-i]=arr[tx+i][ty+side-1];
                    cp[tx+i][ty]=arr[tx+side-1][ty+i];
                    cp[tx][ty+side-1-i]=arr[tx+i][ty];
                    
                }
            }
        }
    }
    
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
            arr[i][j]=cp[i][j];
    
    /*cout <<"===========spin========"<<'\n';
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            cout << arr[i][j]<<' ';
        cout <<'\n';
    }
    cout <<"=============\n";*/
}

void check(){
    int num = pow(2,N);
    
    int tmp[65][65];
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            tmp[i][j]=arr[i][j];
    }

    for(int r=0;r<num;r++){
        for(int c=0;c<num;c++){
            if(tmp[r][c]){
                int cnt=0;
                for(int i=0;i<4;i++){
                    int tx=r+xx[i],ty=c+yy[i];
                    if(tx<0||ty<0||tx>=num||ty>=num)
                        continue;
                    if(tmp[tx][ty])
                        cnt++;
                }
                if(cnt<3){
                    arr[r][c]--;
                    //cout << r <<' '<<c <<'\n';
                }
                    
            }
        }
    }
    /*cout <<'\n';
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            cout << arr[i][j]<<' ';
        cout <<'\n';
    }
    cout <<'\n';*/
}

int total=0;

void sum(){
    int num = pow(2,N);
    for(int r=0;r<num;r++){
        for(int c=0;c<num;c++){
            total+=arr[r][c];
        }
    }
}

int sol=0;

void bfs(int x, int y){
    int num = pow(2,N);
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    int cnt=1;
    while(!q.empty()){
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>=num||ty>=num||visited[tx][ty])
                continue;
            if(arr[tx][ty]){
                visited[tx][ty]=1;
                cnt++;
                q.push({tx,ty});
            }
        }
    }
    sol=max(cnt,sol);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    int num = pow(2,N);
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            cin >> arr[i][j];
    }
    int L;
    total=0;
    while(Q--){
        cin >> L;
        spin(L);
        check();
        
    }
    sum();
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(arr[i][j]&&!visited[i][j]){
                bfs(i,j);
            }
        }
    }
    cout << total<<'\n';
    cout << sol <<'\n';
    return 0;
}