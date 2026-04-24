#include<bits/stdc++.h>

using namespace std;

int N;
int arr[21][21];
vector<int>comb;
vector<int>start;
vector<int>l;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    }
    for(int i=0;i<N/2;i++)
        comb.push_back(0);
    for(int i=0;i<N/2;i++)
        comb.push_back(1);
    int s_score,l_score;
    int sol=123456789;
    do{
        s_score=0,l_score=0;
        start.clear();
        l.clear();
        for(int i=0;i<comb.size();i++){
            if(!comb[i]){
                start.push_back(i);
            }
            else{
                l.push_back(i);
            }
        }
        for(int i=0;i<start.size();i++){
            for(int j=i+1;j<start.size();j++)
                s_score+=(arr[start[i]][start[j]]+arr[start[j]][start[i]]);
        }
        for(int i=0;i<l.size();i++){
            for(int j=i+1;j<l.size();j++)
                l_score+=(arr[l[i]][l[j]]+arr[l[j]][l[i]]);
        }
        sol = min(sol,abs(s_score-l_score));
    }while(next_permutation(comb.begin(),comb.end()));
    cout << sol;
    return 0;
}