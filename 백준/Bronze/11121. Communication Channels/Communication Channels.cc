#include<iostream>
#include<string>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int n; cin>>n;
    while(n--){
        string a,b;
        cin>>a>>b;
        if(a==b)
            cout<<"OK\n";
        else
            cout<<"ERROR\n";
    }
}