#include<iostream>
#include<cmath>

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
    int sol= N, cnt=0;
    while(sol>9){
        int tmp=sol, t1=1;
        while(tmp>0){
            t1*=tmp%10;
            tmp/=10;
        }
        sol=t1;
        cnt++;
    }
    cout << cnt <<'\n';
    return 0;
}
