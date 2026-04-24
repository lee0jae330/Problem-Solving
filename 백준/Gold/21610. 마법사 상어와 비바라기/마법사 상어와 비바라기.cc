#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[51][51];
int cloud[51][51];

int xx[8]={0,-1,-1,-1,0,1,1,1};
int yy[8]={-1,-1,0,1,1,1,0,-1};

void move_cloud(int d,int s){
    s%=N; //거리 갱신
    d--;
    int tmp[51][51]={0,};
    
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if(cloud[x][y]){
                int tx = x+xx[d]*s,ty=y+yy[d]*s;
                if(tx>=N)
                    tx-=N;
                if(tx<0)
                    tx+=N;
                if(ty>=N)
                    ty-=N;
                if(ty<0)
                    ty+=N;
                tmp[tx][ty]=1; //구름 이동
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cloud[i][j]=tmp[i][j];
    }
    
    
}

void rain(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(cloud[i][j])
                arr[i][j]++;
        }
    }
}

void waterCopy(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(cloud[i][j]){
                int cnt=0;
                for(auto d: {1,3,5,7} ){
                    int tx=i+xx[d],ty=j+yy[d];
                    if(tx<0||ty<0||tx>=N||ty>=N)
                        continue;
                    if(arr[tx][ty])
                        cnt++;
                }
                arr[i][j]+=cnt;
            }
        }
    }
}

void make_cloud(){
    int tmp[51][51]={0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]>=2&&!cloud[i][j]){
                tmp[i][j]=1;
                arr[i][j]-=2;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cloud[i][j]=tmp[i][j];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N  >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    cloud[N-1][0]=1;
    cloud[N-1][1]=1;
    cloud[N-2][0]=1;
    cloud[N-2][1]=1;
    while(M--){
        int d,s;
        cin >> d >> s;
        move_cloud(d,s);
        rain();
        waterCopy();
        make_cloud();
    }
    int sol=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            sol+=arr[i][j];
    }
    cout <<sol<<'\n';
    return 0;
}