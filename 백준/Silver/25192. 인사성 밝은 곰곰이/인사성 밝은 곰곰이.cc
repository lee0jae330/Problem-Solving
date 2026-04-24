#include<iostream>
#include<set>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

set<string>s;

int main(void){
    fastio();
    int N,result=0,flag=0;
    cin>>N;
    while(N--){
       string str;
       cin>>str;
        if(str=="ENTER"){
            result+=s.size();
            s.clear();
        }
       else{
           s.insert(str);
       }
    }
    result+=s.size();
    cout<<result;
    
}