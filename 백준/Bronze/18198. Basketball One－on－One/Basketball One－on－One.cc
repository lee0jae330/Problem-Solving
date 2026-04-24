#include<iostream>
#include<string>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin>>s;
    int a=0,b=0,flag=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')
            flag=1;
        else if(s[i]=='B')
            flag=0;
       else{
       
                
               
 
           if(flag){
               a+=s[i]-'0';
           }
           else{
               b+=s[i]-'0';
           }
            
 
       }
    }
    if(a>b)
        cout<<'A';
    else
        cout <<'B';
}