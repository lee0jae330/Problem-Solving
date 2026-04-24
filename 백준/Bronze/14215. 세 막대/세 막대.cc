#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(void){
    fastio();
    vector<int>v(3);
    cin >>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.end());
    int sum=v[0]+v[1];
    int t=min(v[2], v[0]+v[1]-1);
    sum +=t;
    cout << sum;
    
    return 0;
}