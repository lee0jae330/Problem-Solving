#include<iostream>
#include<deque>
#include<queue>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int board[101][101]; //뱀의 상태표시

queue<pair<int,char>>changeDirection; //뱀의 방향 변환 저장
deque<pair<int,int>>snake;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};




int main(){
    fastio();
    int N,K, L;
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int ax, ay; 
        cin>> ax>> ay;
        board[ax-1][ay-1]=2; //사과는 1로 표시
    }
    
    cin >> L;
    for(int i=0;i<L;i++){
        int t; char dir;
        cin >>t>>dir;
        changeDirection.push({t,dir});
    }
    snake.push_back({0,0});
    board[0][0]=1;
    int snakedir=0, flag=0, gameTime=0;
    while(!flag){
        gameTime++;
        int x=snake.front().first, y=snake.front().second; //머리의 좌표
        int tx=x+xx[snakedir], ty=y+yy[snakedir]; //다음 위치
                if(tx<0||ty<0||tx>=N||ty>=N){ //머리를 벽에 박았을때
            flag=1;
            break;
        }
        if(board[tx][ty]==1){ //자기자신에 박았을때
            flag=1;
            break;
        }
        //안죽었을 박았을때
        if(board[tx][ty]==2){ //사과를 먹었을때
            board[tx][ty]=1;
            snake.push_front({tx,ty});
            board[tx][ty]=0;
        }
        else{ //사과를 못먹었을때 -> 꼬리가 줄어들고, 머리 위치 갱신
            int tailx=snake.back().first, taily=snake.back().second;
            board[tailx][taily]=0;
            snake.pop_back();
            board[tx][ty]=1;
            snake.push_front({tx,ty});
        }
        //방향 변환 여부
        int now= changeDirection.front().first;
        if(gameTime==now){ //->방향 변환
            char d = changeDirection.front().second;
            if(snakedir==0){
                if(d=='L'){
                   snakedir=3;
                }
                else{
                    snakedir=1;
                }
            }
            else if(snakedir==1){
                if(d=='L'){
                   snakedir=0;
                }
                else{
                    snakedir=2;
                }
            }
            else if(snakedir==2){
                if(d=='L'){
                   snakedir=1;
                }
                else{
                    snakedir=3;
                }
            }
            else{
                if(d=='L'){
                   snakedir=2;
                }
                else{
                    snakedir=0;
                }
            }
            changeDirection.pop();
        }
            }
    cout<<gameTime<<'\n';
    return 0;
}