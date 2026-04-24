#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int N,score=-1;
    cin>>N;
    while(N--){
        int tmp=0;
        for(int i=0;i<3;i++){
            int x,y,z;
            cin>>x>>y>>z;
            tmp+=(a*x+b*y+c*z);
        }
       score=max(score,tmp);
    }
    cout <<score;
}