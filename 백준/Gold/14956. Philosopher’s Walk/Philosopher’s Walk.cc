#include<bits/stdc++.h>

using namespace std;

pair<long long,long long> rec(long long k, long long num, long long rev){
    if(rev<0)
        rev+=4;
    if(rev>=4)
        rev-=4;
    if(k==2){//base condition
        if(!rev){
            switch(num){
                case 1:
                    return {1,1};
                case 2:
                    return {1,2};
                case 3:
                    return {2,2};
                default:
                    return {2,1};
            }
        }
        else if(rev==1){
            switch(num){
                case 1:
                    return {1,1};
                case 2:
                    return {2,1};
                case 3:
                    return {2,2};
                default:
                    return {1,2};
            }
        }
        else if(rev==2){
            switch(num){
                case 1:
                    return {2,2};
                case 2:
                    return {2,1};
                case 3:
                    return {1,1};
                default:
                    return {1,2};
            }
        }
        else{
            switch(num){
                case 1:
                    return {2,2};
                case 2:
                    return {1,2};
                case 3:
                    return {1,1};
                default:
                    return {2,1};
            }
        }
    }
    long long h=k/2, section,r=0;
    long long area=h*h;
    if(num<=area){//1
        section=1;
    }
    else if(num<=2*area){//2
        section=2;
    }
    else if(num<=3*area){//3
        section=3;
    }
    else{//4
        section=4;
    }
    if(section==1){
        if(rev==0||rev==2){
            r=1;
        }
        else
            r=-1;
    }
    else if(section==4){
        if(rev==0||rev==2){
            r=-1;
        }
        else
            r=1;
    }
    if(!rev){
        switch(section){
            case 1:
                return {rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
            case 2:
                return {rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
            case 3:
                return  {h+rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
            default:
                return {h+rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
        }
    }
    else if(rev==1){
        switch(section){
            case 1:
                return {rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
            case 2:
                return {h+rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
            case 3:
                return  {h+rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
            default:
                return {rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
        }
    }
    else if(rev==2){
        switch(section){
            case 1:
                return {h+rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
            case 2:
                return {h+rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
            case 3:
                return  {rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
            default:
                return {rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
        }
    }
    else{
        switch(section){
            case 1:
                return {h+rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
            case 2:
                return {rec(k/2,num-(section-1)*area,rev+r).first,h+rec(k/2,num-(section-1)*area,rev+r).second};
            case 3:
                return  {rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
            default:
                return {h+rec(k/2,num-(section-1)*area,rev+r).first,rec(k/2,num-(section-1)*area,rev+r).second};
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long k, num;
    cin >> k>>num;
    pair<long long,long long>p;
    p=rec(k,num,0);
    cout <<p.first<<' '<<p.second;
    return 0;
}