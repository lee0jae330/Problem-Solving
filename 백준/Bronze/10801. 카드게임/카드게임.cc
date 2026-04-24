#include<iostream>

using namespace std;

int arr[10],brr[10];

int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int t=9,a=0,b=0;
    for(int i=0;i<10;i++){
       cin>>arr[i];
        
        
        

       
     
    }
    for(int i=0;i<10;i++){
    
      cin>>brr[i];
        if(arr[i]>brr[i])
            a++;
        else if(arr[i]<brr[i])
            b++;
    }
    if(a>b)
        cout<<"A";
    else if(a<b)
        cout<<'B';
    else
        cout<<"D";
}