#include<iostream>
#include<string>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(void){
    fastio();
    int T;
    cin >>T;
    while(T--){
        double a;
        string s;
        cin >>a>>s;
        cout <<fixed;
        cout.precision(4);
        if(s=="kg"){
            cout << a*2.2046<<" lb"<<'\n';
        }
        else if(s=="lb"){
            cout <<a*0.4536<<" kg"<<'\n';
        }
        else if(s=="l"){
            cout <<a*0.2642<<" g"<<'\n';
        }
        else
            cout <<a*3.7854<<" l"<<'\n';
    }
    return 0;
}