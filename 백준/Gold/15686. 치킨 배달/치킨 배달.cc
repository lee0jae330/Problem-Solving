#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[51][51];
int cp[51][51];

int sol=123456789;


vector<pair<int,int>>chick;
vector<int>comb;



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            cp[i][j]=arr[i][j];
            if(arr[i][j]==2){
                chick.push_back({i,j});
            }
        }
    }
    int numOfchick = chick.size();
    for(int i=0;i<M;i++)
        comb.push_back(0);
    for(int i=0;i<numOfchick-M;i++)
        comb.push_back(1);
    do{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                arr[i][j]=cp[i][j];
        }
        int tmp_sol=0;
        for(int i=0;i<comb.size();i++){
            if(comb[i]){
                auto [r,c]=chick[i];
                arr[r][c]=0; 
                //선택 안된 곳을 빈칸으로 바꾸기
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arr[i][j]==1){
                    int dist=123456789;
                    for(int r=0;r<N;r++){
                        for(int c=0;c<N;c++){
                            if(arr[r][c]==2){
                                int tmp = abs(i-r)+abs(j-c);
                                dist=min(tmp,dist);
                            }
                        }
                    }
                    tmp_sol +=dist;
                }
            }
        }
        sol=min(tmp_sol,sol);
        
    }while(next_permutation(comb.begin(),comb.end()));
    cout << sol <<'\n';
    return 0;
    
}