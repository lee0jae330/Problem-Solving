#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


bool comp(string s1, string s2){
    return s1>s2;
}

class room{
    public:
        int standardLevel;
        int numOfpeople;
        bool isStart=false;
        vector<pair<string,int>>players; //플레이어 명단
    public:
        room(int level, int num){ //생성자
            this->standardLevel = level;
            this->numOfpeople = num;
        }
        bool canParticipate(int level){ //플레이어 참석여부
            if(isStart)
                return false;
            int mn =standardLevel-10, mx=standardLevel+10;
            if(level>=mn&&level<=mx){
                return true;
            }
            else return false;
        }
        void addPlayers(string name, int level){
            this->players.push_back({name, level});
            if(players.size()==numOfpeople){
                this->isStart=true;
            }
        }
        void printPlayers(){
            sort(players.begin(),players.end());
            for(int i=0;i<players.size();i++){
                cout<< players[i].second <<' '<< players[i].first<<'\n';
            }
        }
};



int main(){
    fastio();
    int p,m; //플레이어 수, 방의 정원
    vector<room>rms;
    cin >>p>>m;
    for(int i=0;i<p;i++){
        int l;
        string n;
        cin >> l >> n;//플레이어 레벨, 플레이어 닉네임
        if(rms.empty()){ //방이 없을 때
            room newRoom=room(l,m);
            newRoom.addPlayers(n,l);
            rms.push_back(newRoom);
        }
        else{
            int flag=0; //방 참가 여부
            for(int s=0;s<rms.size();s++){
                if(rms[s].canParticipate(l)){ //참가 가능시
                    rms[s].addPlayers(n,l);
                    flag=1;
                    break;
                }
                else{
                    continue;
                }
                
            }
            if(!flag){
                room newRoom=room(l,m);
                newRoom.addPlayers(n,l);
                rms.push_back(newRoom);
            }
        }
    }
    for(int i=0;i<rms.size();i++){
        if(rms[i].isStart)
            cout<< "Started!"<<'\n';
        else
            cout<<"Waiting!"<<'\n';
        rms[i].printPlayers();
    }
    return 0;
}