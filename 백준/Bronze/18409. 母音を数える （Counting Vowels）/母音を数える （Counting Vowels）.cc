#include<iostream>
#include<string>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int N,cnt=0; cin>>N;
    for(int i=0;i<N;i++){
        char c; cin>>c;
        if(c=='a'||c=='o'||c=='u'||c=='i'||c=='e')
    cnt++;
    }
    cout<<cnt;
        
}