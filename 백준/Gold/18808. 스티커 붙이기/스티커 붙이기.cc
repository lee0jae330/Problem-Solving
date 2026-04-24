 #include<bits/stdc++.h>

using namespace std;

int N, M, K,R,C;
int arr[41][41];
int cp[11][11];
int sticker[11][11];

int check(){ //확인 함수 자리를 찾으면 1, 못찾으면 0
    int sx=0,sy=0;
    for(int x=0;x<=N-R;x++){
        for(int y=0;y<=M-C;y++){
            int tx = sx+x,ty=sy+y;
            //cout << tx<<' '<<ty <<'\n';
            int flag=0;
            for(int i=tx;i<tx+R;i++){
                for(int j=ty;j<ty+C;j++){
                    if(arr[i][j]&&sticker[i-tx][j-ty])
                        flag=1;
                }
            }
            if(!flag){
                for(int i=tx;i<tx+R;i++){
                    for(int j=ty;j<ty+C;j++){
                        if(sticker[i-tx][j-ty])
                            arr[i][j]=sticker[i-tx][j-ty];
                    }
                }
                /*for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++)
                        cout << arr[i][j]<<' ';
                    cout<<'\n';
                }
                cout <<'\n';*/
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int r=0;r<K;r++){
        cin >> R >> C;
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                cin >> sticker[i][j]; 
        }
        

        for(int turn=0;turn<4;turn++){
            if(check()){ //f가 1이면 자리를 찾은거임
                break;
            }
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cp[j][R-1-i]=sticker[i][j];
                }
            }
            swap(R,C);
            memset(sticker,0,sizeof(sticker));
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++)
                    sticker[i][j]=cp[i][j];
            }
            /*
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++)
                    cout << sticker[i][j]<<' ';
                cout <<'\n';
            }
            cout <<'\n';*/
        }
        
        
    }
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(arr[i][j])
                cnt++;
    }
    cout <<cnt <<'\n';
    return 0;
}
