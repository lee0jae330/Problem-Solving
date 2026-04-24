#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[10][10];

int main(void){
    fastio();
    int mx=-1,x,y;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >>arr[i][j];
            if(arr[i][j]>mx){
                mx=arr[i][j];
                x=i+1, y=j+1;
            }
            
        }
            
        
    }
    cout<< mx<<'\n'<<x<<' '<<y<<'\n';
}