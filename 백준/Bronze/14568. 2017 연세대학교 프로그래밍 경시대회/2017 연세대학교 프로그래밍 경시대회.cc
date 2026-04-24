#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(void){
    fastio();
    int N,result=0,a=2;
    cin >>N;
    while(N-a>=4){
        int tmp= N-a;
        for(int i=1;i<=tmp;i++){
            int gap= tmp-2*i;
            if(gap<2)
                break;
            result++;
        }
        a+=2;
    }
    cout << result <<'\n';
    return 0;
}