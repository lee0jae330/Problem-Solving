#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int>v;

int main(void){
    fastio();
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        int num; cin >>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v[N-1];
}