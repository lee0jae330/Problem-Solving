#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[10][10];

int main(void){
    fastio();
    int  N;
    string s;
    cin >>N>>s;
    int len= s.size();
    for(int i=len-5;i<len;i++)
        cout<<s[i];
}