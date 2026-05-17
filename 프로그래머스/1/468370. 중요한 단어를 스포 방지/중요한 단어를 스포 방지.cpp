#include<bits/stdc++.h>


using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    int idx = 0, len = message.length();
    
    set<string>no_spo, spo;
    
    for(auto ranges: spoiler_ranges) {
        int s = ranges[0], e = ranges[1];
        
        while(idx <= e) {
            string str = "";    
            int flag = 0;
            for(int i = idx; i < len; i++) {    
                if(message[i] == ' ') {
                    idx = i+1;
                    
                    if(flag) {
                        if(no_spo.find(str) == no_spo.end()) {
                            spo.insert(str);
                        }
                    } else {
                        if(spo.find(str) != spo.end()) {
                            spo.erase(str);
                        }
                        no_spo.insert(str);
                    }
                    break;
                }
                
                if(i>= s && i<= e) {
                    flag = 1;
                }
                
                str.push_back(message[i]);
                
                if(i == len -1) {
                    idx = i+1;
                    if(flag) {
                        if(no_spo.find(str) == no_spo.end()) {
                            spo.insert(str);
                        }
                    } else {
                        if(spo.find(str) != spo.end()) {
                            spo.erase(str);
                        }
                        no_spo.insert(str);
                    }
                    break;
                }
            }         
        }
    }
    string str = "";
    for(int i = idx; i < len ; i++) {
        if(message[i] == ' ') {
            if(spo.find(str) != spo.end()) {
                spo.erase(str);
            }
            no_spo.insert(str);
            str = "";
            continue;
        }
        str.push_back(message[i]);
    }
    
    for(string s: spo) {
        cout << quoted(s);
    }
    cout <<'\n';
    for(string s: no_spo) {
        cout << quoted(s);
    }
    
    cout << spo.size() <<'\n';

    return spo.size();
}