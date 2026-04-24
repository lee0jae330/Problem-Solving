#include<bits/stdc++.h>

using namespace std;

int N, M;
int order[60][60];
int arr[60][60];

int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};

int sx,sy;
int sol=0;


vector<pair<int,int>>cord;

void print_marble(){
    cout <<"------marble--------\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << arr[i][j]<<' ';
        cout <<'\n';
    }
    cout <<"-------------------\n";
}

void make_order(){
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    int x=N/2, y=N/2;
    int cnt=1;
    int d=0;
    int weight=1;
    int flag=0;
    while(cnt<=N*N-1){
        for(int i=0;i<weight;i++){
            int tx=x+dx[d],ty=y+dy[d];
            order[tx][ty]=cnt;
            if(cnt<=N*N-1)
                cord.push_back({tx,ty});
            cnt++;
            x=tx,y=ty;
            
        }
        d++;
        if(d==4)
            d=0;
        flag++;
        if(flag==2){
            flag=0;
            weight++;
        }
    }
}

void throw_ice(int d, int s){
    d--;
    int x=sx,y=sy;
    for(int i=1;i<=s;i++){
        int tx=x+xx[d],ty=y+yy[d];
        arr[tx][ty]=0;
        x=tx,y=ty;
    }
}

void move_marble(){
    int sz=cord.size();
    for(int i=0;i<sz-1;i++){
        auto [x,y]=cord[i];
        if(!arr[x][y]){
            for(int j=i+1;j<sz;j++){
                auto[tx,ty]=cord[j];
                if(arr[tx][ty]){
                    swap(arr[x][y],arr[tx][ty]);
                    break;
                }
            }
        }
    }
}

int isboom;
void boom_marble(){
    int sz=cord.size();
    for(int i=0;i<sz-1;i++){
        auto [x,y]=cord[i];
        vector<pair<int,int>>v;
        v.push_back({x,y});
        if(!arr[x][y])
            break;
        for(int j=i+1;j<sz;j++){
            auto [tx,ty]=cord[j];
            if(arr[tx][ty]==arr[x][y]){
                v.push_back({tx,ty});
                i=j;
            }
            else{
                break;
            }
        }
        if(v.size()>=4){
            sol+=v.size()*arr[x][y];
            for(auto a: v){
                auto [r,c]=a;
                arr[r][c]=0;
                isboom=1;
            }
        }
    }
}

void make_marble(){
    int sz=cord.size();
    int idx=0;
    int tmp[60][60]={0,};
    for(int i=0;i<sz-1;i++){
        auto [x,y]=cord[i];
        int num = arr[x][y];
        int cnt=1;
        if(!num)
            break;
        for(int j=i+1;j<sz;j++){
            auto[tx,ty]=cord[j];
            if(arr[tx][ty]==arr[x][y]){
                cnt++;
                i=j;
            }
            else
                break;
        }
        //cout << num <<' '<<cnt <<'\n';
        if(idx<sz){
            auto[x,y]=cord[idx];
            tmp[x][y]=cnt;
            idx++;
        }
        else
            break;
        if(idx<sz){
            auto[x,y]=cord[idx];
            tmp[x][y]=num;
            idx++;
        }
        else
            break;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            arr[i][j]=tmp[i][j];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>N >> M;
    //구슬 순서 만들기
    make_order();
    //상어 위치
    //cout << cord.size()<<'n';
    sx=N/2,sy=N/2;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    int d, s;
    while(M--){
        cin >> d >>s;
        //얼음던지기
        throw_ice(d,s);
        //print_marble();
        //구슬 움직이기
        move_marble();
        //print_marble();
        //터뜨리기
        while(1){
            isboom=0;
            boom_marble();
            //print_marble();
            move_marble();
            //print_marble();
            if(!isboom)
                break;
        }
        //구슬만들기 <- 추가해야함
        make_marble();
        //print_marble();
    }
    cout << sol <<'\n';
    return 0;
}
