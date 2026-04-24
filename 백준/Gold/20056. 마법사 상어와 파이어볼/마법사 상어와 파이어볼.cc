#include<bits/stdc++.h>

using namespace std;

int N,M,K;
int xx[8]={-1,-1,0,1,1,1,0,-1};
int yy[8]={0,1,1,1,0,-1,-1,-1};

class fireball{
    public:
        int r,c;
        int mass;
        int speed;
        int dir;
        int sz=1;
        vector<int>mergeDir;
        
    public:
        fireball(){
            sz=0;
        }
        fireball(int r, int c, int mass, int speed, int dir){
            this->r=r;
            this->c=c;
            this->mass=mass;
            this->speed=speed;
            this->dir=dir;
            mergeDir.push_back(dir);
        }
};

fireball arr[51][51];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    while(M--){
        int r,c,m,s,d;
        cin >>r >> c >> m >> s >>d;
        arr[r-1][c-1]=fireball(r,c,m,s,d);
    }
    while(K--){ //이동
        fireball cp[51][51]; //이동 후의 파이어볼상태
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                fireball tmp = arr[i][j];
                if(!tmp.sz) //빈칸의 경우
                    continue;
                if(tmp.sz==1){
                   //파이어볼이 하나만 있는 경우
                    int sp = tmp.speed;
                    sp%=N;
                    int x=i,y=j;
                    int d=tmp.dir;
                    int tx=x+sp*xx[d],ty=y+sp*yy[d];
                    if(tx>=N)
                        tx-=N;
                    if(tx<0)
                        tx+=N;
                    if(ty>=N)
                        ty-=N;
                    if(ty<0)
                        ty+=N;
                    if(!cp[tx][ty].sz){
                        //이동할 곳이 빈칸인 경우
                        cp[tx][ty]=arr[i][j]; //이동시키기
                    }
                    else{
                        cp[tx][ty].sz++; //개수 증가
                        cp[tx][ty].mass+=tmp.mass; //질량 합치기
                        cp[tx][ty].speed+=tmp.speed; //속도 합치기
                        cp[tx][ty].mergeDir.push_back(tmp.dir); //방향들 추가
                    }
                }
                else{
                    //파이어볼이 2개 이상인 경우
                    int x=i,y=j;
                    int m = tmp.mass / 5; //질량 /5
                    if(!m)
                        continue; //없어짐
                    int s = tmp.speed / tmp.sz;
                    int flag = tmp.mergeDir[0]%2;
                    int f=0;
                    for(int i=1;i<tmp.mergeDir.size();i++){
                        int t = tmp.mergeDir[i]%2;
                        if(t != flag){
                            f=1;
                            break;
                        }
                    }
                    
                    if(!f){
                        //방향이 모두 홀수 or 짝수인 경우
                        for(int d=0;d<=6;d+=2){
                            int sp = s%N;
                            int tx=x+sp*xx[d],ty=y+sp*yy[d];
                            if(tx>=N)
                                tx-=N;
                            if(tx<0)
                                tx+=N;
                            if(ty>=N)
                                ty-=N;
                            if(ty<0)
                                ty+=N;
                            if(!cp[tx][ty].sz){
                                //이동할 곳이 빈칸인 경우
                                cp[tx][ty]=fireball(tx,ty,m,s,d); //이동시키기
                            }
                            else{
                                cp[tx][ty].sz++; //개수 증가
                                cp[tx][ty].mass+=m; //질량 합치기
                                cp[tx][ty].speed+=s; //속도 합치기
                                cp[tx][ty].mergeDir.push_back(d); //방향들 추가
                            }
                        }
                    }
                    else{
                        for(int d=1;d<=7;d+=2){
                            int sp = s%N;
                            int tx=x+sp*xx[d],ty=y+sp*yy[d];
                            if(tx>=N)
                                tx-=N;
                            if(tx<0)
                                tx+=N;
                            if(ty>=N)
                                ty-=N;
                            if(ty<0)
                                ty+=N;
                            if(!cp[tx][ty].sz){
                                //이동할 곳이 빈칸인 경우
                                cp[tx][ty]=fireball(tx,ty,m,s,d); //이동시키기
                            }
                            else{
                                cp[tx][ty].sz++; //개수 증가
                                cp[tx][ty].mass+=m; //질량 합치기
                                cp[tx][ty].speed+=s; //속도 합치기
                                cp[tx][ty].mergeDir.push_back(d); //방향들 추가
                            }
                        }
                    }
                }
            }
        }

        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                arr[i][j]=cp[i][j];
        }
    }
    int sol=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!arr[i][j].sz)
                continue;
            
            if(arr[i][j].sz==1){
                sol+=arr[i][j].mass;
            }
            else{
                int m=arr[i][j].mass/5;
                sol+=m*4;
            }
        }
    }
    cout << sol;
    return 0;
}