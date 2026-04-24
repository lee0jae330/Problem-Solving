#include<bits/stdc++.h>

using namespace std;

int N;


int arr[501][501];

int xx[4]={0,1,0,-1};
int yy[4]={-1,0,1,0};

int sol=0;

int check(int x, int y){
    if(x<0||y<0||x>=N||y>=N)
        return 0;
    return 1;
}

void move(int x, int y, int dir){ //토네이도가 이동할 칸의 좌표, 방향
    int one = arr[x][y] / 100;
    int two = arr[x][y]*2 /100;
    int five = arr[x][y]*5 /100;
    int seven = arr[x][y]*7/100;
    int ten = arr[x][y]*10/100;
    
    int alpha = arr[x][y]-(2*(one+two+seven+ten)+five);
    int tx,ty;
    if(dir==0){ //왼쪽
        tx=x-1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x+1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x-2,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x+2;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x-1;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x+1;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x-1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x+1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x,ty=y-2;
        if(check(tx,ty))
            arr[tx][ty]+=five;
        else
            sol+=five;
        tx=x,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=alpha;
        else
            sol+=alpha;

    }
    else if(dir==1){
        //아래
        tx=x-1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x-1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x,ty=y+2;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x,ty=y-2;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x+1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x+1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x+2,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=five;
        else
            sol+=five;
        tx=x+1,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=alpha;
        else
            sol+=alpha;
        
        
        
    }
    else if(dir==2){
        //오른쪽
        tx=x-1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x+1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x-2,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x+2,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x-1,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x+1,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x-1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x+1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x,ty=y+2;
        if(check(tx,ty))
            arr[tx][ty]+=five;
        else
            sol+=five;
        tx=x,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=alpha;
        else
            sol+=alpha;
    }
    else{
        //위쪽
        tx=x+1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x+1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=one;
        else
            sol+=one;
        tx=x,ty=y+2;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x,ty=y-2;
        if(check(tx,ty))
            arr[tx][ty]+=two;
        else
            sol+=two;
        tx=x,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;    
        tx=x,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=seven;
        else
            sol+=seven;
        tx=x-1,ty=y+1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x-1,ty=y-1;
        if(check(tx,ty))
            arr[tx][ty]+=ten;
        else
            sol+=ten;
        tx=x-2,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=five;
        else
            sol+=five;
        tx=x-1,ty=y;
        if(check(tx,ty))
            arr[tx][ty]+=alpha;
        else
            sol+=alpha;
    }
    arr[x][y]=0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    }
    //arr[N/2][N/2]=1;
    int cnt=2;
    int weight=1;
    int flag=0;
    int dir=0;
    int x=N/2,y=N/2;
    while(cnt<=N*N){
        for(int i=0;i<weight;i++){
            //달팽이 배열 순서로 이동
            int tx=x+xx[dir],ty=y+yy[dir];
            //arr[tx][ty]=cnt;
            move(tx,ty,dir);
            cnt++;
            x=tx,y=ty;
        }
        dir++;
        flag++;
        if(dir==4)
            dir=0;
        if(flag==2){
            flag=0;
            weight++;
        }
    }
    
    /*for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << arr[i][j]<<' ';
        cout <<'\n';
    }*/
    cout << sol <<'\n';
}