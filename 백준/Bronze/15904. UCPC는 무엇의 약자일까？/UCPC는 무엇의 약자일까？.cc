#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[5];

int main(void){
    string s;
    getline(cin ,s);
    int U=0,C1=0,P=0,C2=0;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='U')
            U=1;
        if(s[i]=='C'&&U)
            C1=1;
        if(s[i]=='P'&&U&&C1)
            P=1;
        if(s[i]=='C'&&U&&C1&&P)
            C2=1;
    }
    if(U&&C1&&P&&C2)
        cout << "I love UCPC"<<'\n';
else{
        cout << "I hate UCPC"<<'\n';
    }
    return 0;
}