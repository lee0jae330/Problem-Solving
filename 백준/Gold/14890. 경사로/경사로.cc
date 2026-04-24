#include<bits/stdc++.h>

using namespace std;

int N, L;
int arr[101][101];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    }
    //cout <<'\n';
    int sol=0;
    for(int r=0;r<N;r++){
        int cnt=0, canGo=1, flag=0;
        for(int c=0;c<N;c++){
            if(!c){
                cnt++;
            }
            else{
                if(arr[r][c]==arr[r][c-1]){
                    cnt++;
                    if(flag){
                        if(cnt>=L){
                            cnt-=L;
                            flag=0;
                        }
                    }
                }
                else{
                    if(flag){
                        canGo=0;
                        break;
                    }
                    if(arr[r][c]+1==arr[r][c-1]){
                        flag=1;
                        cnt=1;
                        if(cnt>=L){
                            flag=0;
                            cnt-=L;
                        }
                    }
                    else if(arr[r][c]==arr[r][c-1]+1){
                        if(cnt>=L){
                            cnt=1;
                        }
                        else{
                            canGo=0;
                            break;
                        }
                    }
                    else{ // 경사가 1 보다 많이 차이나면 못지나감
                        canGo=0;
                        break;
                    }
                }
            }
        }
        if(canGo&&!flag){
            /*for(int i=0;i<N;i++){
                cout << arr[r][i]<<' ';
            }
            cout <<'\n';*/
            sol++;
        }
    }
    //cout <<'\n';
    for(int c=0;c<N;c++){
        int cnt=0, canGo=1, flag=0;
        for(int r=0;r<N;r++){
            if(!r){
                cnt++;
            }
            else{
                if(arr[r][c]==arr[r-1][c]){
                    cnt++;
                    if(flag){
                        if(cnt>=L){
                            cnt-=L;
                            flag=0;
                        }
                    }
                }
                else{
                    if(flag){
                        canGo=0;
                        break;
                    }
                    if(arr[r][c]+1==arr[r-1][c]){
                        flag=1;
                        cnt=1;
                        if(cnt>=L){
                            flag=0;
                            cnt-=L;
                        }
                    }
                    else if(arr[r][c]==arr[r-1][c]+1){
                        if(cnt>=L){
                            cnt=1;
                        }
                        else{
                            canGo=0;
                            break;
                        }
                    }
                    else{ // 경사가 1 보다 많이 차이나면 못지나감
                        canGo=0;
                        break;
                    }
                }
            }
        }
        if(canGo&&!flag){
            /*for(int i=0;i<N;i++){
                cout << arr[i][c]<<' ';
            }
            cout <<'\n';*/
            sol++;
        }
    }
    cout << sol<<'\n';
    return 0;
}