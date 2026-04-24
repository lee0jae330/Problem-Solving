#include<bits/stdc++.h>

using namespace std;

int N;
int arr[12];
int op[4];

vector<int>comb;

int mx = -1e9;
int mn = 1e9;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    for(int i=0;i<4;i++)
        cin >> op[i];
    int oper=0; //+:0 -:1 *:2 /:3
    for(int i=0;i<4;i++){
        for(int j=0;j<op[i];j++)
            comb.push_back(oper);
        oper++;
    }
    int sum=0;
    do{
        sum=arr[0];
        for(int i=0;i<comb.size();i++){
            if(!comb[i]){
                sum+=arr[i+1];
            }
            else if(comb[i]==1){
                sum-=arr[i+1];
            }
            else if(comb[i]==2){
                sum*=arr[i+1];
            }
            else{
                sum/=arr[i+1];
            }
        }
        mx=max(sum,mx);
        mn=min(mn,sum);
    }while(next_permutation(comb.begin(),comb.end()));
    cout << mx<<'\n'<<mn;
    return 0;
}