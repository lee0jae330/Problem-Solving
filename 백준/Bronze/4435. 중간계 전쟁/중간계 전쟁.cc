#include<iostream>

using namespace std;

int main(void){
    int T, cnt=1;
    cin >>T;
    while(T--){
        int a, b, c,d, e, f,g, ta=0,tb=0;
        cin >>a>>b>>c>>d>>e>>f;
        ta=a+2*b+3*c+3*d+4*e+10*f;
        cin >>a>>b>>c>>d>>e>>f>>g;
        tb=a+2*b+2*c+2*d+3*e+5*f+10*g;
        cout << "Battle "<<cnt++ <<": ";
        if(ta>tb)
            cout<<"Good triumphs over Evil"<<'\n';
        else if(ta<tb)
            cout<<"Evil eradicates all trace of Good"<<'\n';
        else
            cout <<"No victor on this battle field"<<'\n';
        
    }
}