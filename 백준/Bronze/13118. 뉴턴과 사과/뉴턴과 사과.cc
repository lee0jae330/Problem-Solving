#include<iostream>

using namespace std;
int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int arr[4],x,y,z;
    for(int i=0;i<4;i++)
        cin >> arr[i];
    cin>>x>>y>>z;
    for(int i=0;i<4;i++){
        if(arr[i]==x){
            cout <<i+1;
            return 0;
        }
    }
    cout <<0;
  
}