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




int main(void){
    fastio();
    int N;
    cin >>N;
    int cur=-1, bat=-1, sol=0;
    while(N--){
        int a;
        cin >>a;
        if(cur!=a){
            cur=a;
            sol+=2;
            bat=2;
        }
        else{
            sol+=2*bat;
            bat=2*bat;
            
        }
        if(sol>=100){
            sol=0;
            cur=-1;
        }
    }
    cout << sol;
    return 0;
}
