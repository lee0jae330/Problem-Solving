#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    cout<<"int a;\n";
    for(int i=1;i<=N;i++){
        cout <<"int ";
        for(int j=1;j<=i;j++)
            cout<<'*';
        cout<<"ptr";
        if(i>1)
            cout <<i;
            cout <<" = &";
        if(i==1)
            cout << "a";
        else
           {
            cout <<"ptr";
            if(i>2)
                cout <<i-1;;
        }
        cout<<";\n";
    }
    
}