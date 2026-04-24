#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}




int main(void){
    fastio();
    double atk1, atk2, hp1, hp2;
    cin >>atk1 >> hp1 >> atk2>>hp2;
    if(ceil(hp1/atk2)>ceil(hp2/atk1))
        cout <<"PLAYER A";
    else if(ceil(hp1/atk2)<ceil(hp2/atk1))
        cout << "PLAYER B";
    else
        cout <<"DRAW";
    return 0;
}
