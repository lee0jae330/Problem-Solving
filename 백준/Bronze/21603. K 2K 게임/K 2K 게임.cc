#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}


vector<int>v;

int main(void){
    fastio();
    int N, K;
    cin >>N>>K;
    int x=K%10, y=2*K%10;
    for(int i=1;i<=N;i++){
        int tmp = i%10;
        if(tmp!=x&&tmp!=y){
            v.push_back(i);
        }
    }
    cout <<v.size()<<'\n';
    for(int i=0;i<v.size();i++)
        cout << v[i]<<' ';
    return 0;
}
