

#include<iostream>

using namespace std;

int main(void){
    
 while(1){
     double n;
     cin >> n;
     if(n<0)
        break;
    cout << fixed;
    cout.precision(2);
    cout <<"Objects weighing "<<n<<" on Earth will weigh "<<n*0.167<<" on the moon."<<'\n';
 }   
}