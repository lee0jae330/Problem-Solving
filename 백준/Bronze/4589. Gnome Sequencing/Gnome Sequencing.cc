#include<iostream>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int n; cin>>n;
    cout <<"Gnomes:\n";
    while(n--){
        int a,b,c; cin>>a>>b>>c;
        if((a<b&&b<c)||(a>b&&b>c))
            cout<<"Ordered\n";
        else
            cout<<"Unordered\n";
    }
}