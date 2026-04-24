#include<bits/stdc++.h>

using namespace std;

int N,M,num;
int arr[8][8];
int field[8][8];
vector<int> v1 = {0,1,2,3};
vector<int> v2={0,1};
vector<int> v3={0};
vector<tuple<int,int,int>>cctv; //좌표, 종류
vector<int>v[8];

int turn[8];
int sol=123456789;

void right(int x, int y){
    for(int i=y;i<M;i++){
        if(field[x][i]==6)
            break;
        field[x][i]=1;
    }
}

void up(int x,int y){
    for(int i=x;i>=0;i--){
        if(field[i][y]==6)
            break;
        field[i][y]=1;
    }
}

void left(int x, int y){
    for(int i=y;i>=0;i--){
        if(field[x][i]==6)
            break;
        field[x][i]=1;
    }
}

void down(int x, int y){
    for(int i=x;i<N;i++){
        if(field[i][y]==6)
            break;
        field[i][y]=1;
    }
}

int check(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            field[i][j]=arr[i][j];
    }
    for(int i=0;i<num;i++){
        auto [x,y,number]=cctv[i];
        int dir = turn[i];
        field[x][y]=1;
        
        if(number==1){
            if(!dir){ // ->
                right(x,y);
            }
            else if(dir==1){ //위
                up(x,y);   
            }
            else if(dir==2){ // <-
                left(x,y);
            }
            else{ //아래
                down(x,y);
            }
        }
        else if(number==2){
            if(!dir){
                right(x,y);
                left(x,y);
            }
            else{
                up(x,y);
                down(x,y);
            }
        }
        else if(number==3){
            if(!dir){ // ->
                right(x,y);
                up(x,y);
            }
            else if(dir==1){ //위
                up(x,y);
                left(x,y);
            }
            else if(dir==2){ // <-
                left(x,y);
                down(x,y);
            }
            else{ //아래
                down(x,y);
                right(x,y);
            }
        }
        else if(number==4){
            if(!dir){ // ->
                right(x,y);
                up(x,y);
                left(x,y);
            }
            else if(dir==1){ //위
                up(x,y); 
                left(x,y);
                down(x,y);
            }
            else if(dir==2){ // <-
                left(x,y);
                down(x,y);
                right(x,y);
            }
            else{ //아래
                down(x,y);
                right(x,y);
                up(x,y);
            }
        }
        else{
            right(x,y);
            left(x,y);
            up(x,y);
            down(x,y);
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!field[i][j])
                cnt++;
        }
    }
    return cnt;
}

void rec(int K){
    if(K==num){
        sol = min(sol,check());
        return;
    }
    for(int i=0;i<v[K].size();i++){
        turn[K]=v[K][i];
        rec(K+1);
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]>0&&arr[i][j]<6){
                if(arr[i][j]==5)
                    v[num] = v3;
                else if(arr[i][j]==2)
                    v[num]=v2;
                else
                    v[num]=v1;
                num++;
                cctv.push_back({i,j,arr[i][j]});
                
            }
        }
    }
    /*cout << num<<'\n';
    for(int i=0;i<num;i++){
        for(auto a: v[i])
            cout << a<<' ';
        cout <<'\n';
    }*/
    rec(0);
    cout << sol;
    return 0;
}
