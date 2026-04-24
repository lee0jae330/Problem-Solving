#include<iostream>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
   int n;cin>>n;
   while(n--){
       int id,a,b,c;
       cin>>id>>a>>b>>c;
       cout << id<<' '<<a+b+c<<' ';
       if(a+b+c>=55&&a>10&&b>7&&c>=12){
           cout<<"PASS\n";
       }
       else
           cout<<"FAIL\n";
   }
}