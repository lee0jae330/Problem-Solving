#include<iostream>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int t=1;
    while(1){
        int n,tmp;
        cin>>n;
        if(!n)
            break;
        while(n--)
            cin>>tmp;
        cout <<"Case "<<t++<<": Sorting... done!\n";
    }
}