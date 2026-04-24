#include<iostream>
#include<string>

using namespace std;

int main(void){
    long long N; 
    cin >>N;
    long long result=1;
    for(int i=2;i<=N;i++){
        result*=i;
        result%=10;
    }
    cout << result%10 <<'\n';
    return 0;
    
}