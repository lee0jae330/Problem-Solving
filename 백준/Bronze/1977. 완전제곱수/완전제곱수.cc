#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int>v;
int main(void){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int n,m,f=0,mx=-1;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        int tmp=sqrt(i);
        
            if(tmp*tmp==i){
                v.push_back(i);
                f+=i;
                
              
              
            }
        
        
    }
    if(!v.size())
       cout<<mx;
    else
   cout <<f<<'\n'<<v[0];
}