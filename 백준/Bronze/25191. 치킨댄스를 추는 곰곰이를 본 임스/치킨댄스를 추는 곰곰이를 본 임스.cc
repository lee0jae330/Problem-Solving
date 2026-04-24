#include<iostream>

using namespace std;

int main(void){
    int N,a,b, result=0;
    cin>>N>>a>>b;
    if(N<=b)
        result=N;
    else{
        result=b;
        N-=b;
        int num= a/2;
        if(N<=num)
            result+=N;
        else{
            result+=num;
          }
      }
     cout<<result;
   }