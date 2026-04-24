#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[5];


int main(void){
    fastio();
    arr[1]=1, arr[4]=2;
    string str;
    cin >>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='A')
            swap(arr[1],arr[2]);
        else if(str[i]=='B')
            swap(arr[1],arr[3]);
        else if(str[i]=='C')
            swap(arr[1], arr[4]);
        else if(str[i]=='D')
            swap(arr[2],arr[3]);
        else if(str[i]=='E')
            swap(arr[2],arr[3]);
        else
            swap(arr[3], arr[4]);
    }
    for(int i=1;i<5;i++)
        if(arr[i]==1)
            cout << i<<'\n';
    for(int i=1;i<5;i++)
        if(arr[i]==2)
            cout << i<<'\n';
    return 0;
}
