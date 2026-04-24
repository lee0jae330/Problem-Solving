#include<bits/stdc++.h>

using namespace std;

int N;
int arr[51][9];
int lineup[9];
int sol=0;

void play(){
    int score=0,idx=0;
    for(int inning=0;inning<N;inning++){
        int board[3], out=0;
        memset(board,0,sizeof(board));
        while(out<3){
            int result = arr[inning][lineup[idx]];
            idx++;
            if(idx==9)
                idx=0;
            if(!result)
                out++;
            else if(result==1){
                if(board[2])
                    score++;
                board[2]=board[1];
                board[1]=board[0];
                board[0]=1;
            }
            else if(result==2){
                if(board[2])
                    score++;
                if(board[1])
                    score++;
                board[2]=board[0];
                board[1]=1;
                board[0]=0;
            }
            else if(result==3){
                if(board[2])
                    score++;
                if(board[1])
                    score++;
                if(board[0])
                    score++;
                board[2]=1;
                board[1]=0;
                board[0]=0;
            }
            else{
                if(board[2])
                    score++;
                if(board[1])
                    score++;
                if(board[0])
                    score++;
                score++;
                board[2]=0;
                board[1]=0;
                board[0]=0;
            }
        }
    }
    if(sol<score){
        sol=score;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<9;j++)
            cin >> arr[i][j];
    vector<int>comb;
    for(int i=1;i<=8;i++)
        comb.push_back(i);
    do{
        for(int i=0;i<3;i++)
            lineup[i]=comb[i];
        lineup[3]=0;
        for(int i=3;i<8;i++)
            lineup[i+1]=comb[i];
        play();
    }while(next_permutation(comb.begin(),comb.end()));
    cout << sol;
    return 0;
}