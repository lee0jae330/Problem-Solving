#include<iostream>
using namespace std;
int main(void){
    int T;
    cin >>T;
    for(int i=1;i<=T;i++){
        int n,a,b, result=0;
        cin >> n >>a>>b;
        for(int j=0;j<n;j++){
            int x, y;
            cin>>x>>y;
            if(x<=a*b)
                result+=y;
        }
        cout << "Data Set "<<i<<":\n";
        cout << result<<'\n'<<'\n';
    }
}