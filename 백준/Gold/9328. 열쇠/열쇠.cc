#include<bits/stdc++.h>

using namespace std;

int T,H,W;
char arr[105][105];
int visited[105][105];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int key[26];
int sol=0;

int bfs(){
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0]=1;
    int isChange=0;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>H+1||ty>W+1||visited[tx][ty])
                continue;
            if(arr[tx][ty]=='*')
                continue;
            else if(arr[tx][ty]=='.'){
                //이동가능한 공간
                visited[tx][ty]=1;
                q.push({tx,ty});
            }
            else if(arr[tx][ty]>='a'&&arr[tx][ty]<='z'){ //열쇠 일때
                if(!key[arr[tx][ty]-'a']){ //기존에 없는 열쇠일때
                    isChange=1; //다음 bfs에 변화가 생김
                    key[arr[tx][ty]-'a']=1;
                }
                arr[tx][ty]='.'; //일반칸으로 바꾸고
                visited[tx][ty]=1;
                q.push({tx,ty});
            }
            else if(arr[tx][ty]>='A'&&arr[tx][ty]<='Z'){
                //문일 때
                if(!key[arr[tx][ty]-'A']){
                    //못 열때
                    continue;
                }
                else{
                    arr[tx][ty]='.';//일반칸으로 바꾸기
                    visited[tx][ty]=1;
                    q.push({tx,ty});
                }
            }
            else{
                //문서
                sol++;
                arr[tx][ty]='.';
                visited[tx][ty]=1;
                q.push({tx,ty});
            }
        }
    }
    return isChange;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        memset(visited,0,sizeof(visited));
        memset(key,0,sizeof(key));
        memset(arr,'.',sizeof(arr));
        sol=0;
        cin >> H >> W;
        
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++)
                cin >> arr[i][j];
        }
        string tmp;
        cin >> tmp;
        if(tmp!="."){
            for(auto c : tmp){
                key[c-'a']=1;
            }
        }
        int f=1;
        while(1){
            memset(visited,0,sizeof(visited));
            if(!f)
                break;
            f=bfs();
        }
        cout << sol <<'\n';
    }
    return 0;
}