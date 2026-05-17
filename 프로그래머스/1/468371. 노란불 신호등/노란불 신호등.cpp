#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> signals) {
    vector<vector<int>>v;
    for(int i =0 ; i< signals.size();i++) {
        vector<int>tmp(1500011,0);
        v.push_back(tmp);
    }
    
    for(int i = 0 ; i < signals.size();i++) {
        int idx = 1;
cout << v[i].size() <<'\n';
        while(idx <= 1500000) {
            for(int j = 0 ; j < 3;j++) {
                for(int k =0  ; k < signals[i][j];k++) {
                    if(j ==1) {
                        v[i][idx] = 1;
                    }
                    idx++;
                }
            }
        }
    }
    
    for(int i =1 ; i <=1500000;i++) {
        int flag = 0;
        for(int j=0;j<signals.size();j++) {
            if(!v[j][i]){
                flag= 1;
                break;
            }
        }
        if(!flag) {
            cout << i <<'\n';
            return i;
        }
    }
    return -1;
}