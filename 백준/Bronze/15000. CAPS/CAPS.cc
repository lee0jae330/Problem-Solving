#include<iostream>
#include<string>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    string s;
    cin >>s;
    
    for(int i=0;i<s.size();i++){
      s[i]-=32 ;
    }
       
    cout<<s;
}