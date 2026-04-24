#include<iostream>
#include<string>

using namespace std;

int main(void){
    while(1){
        string s;
        int age, weight;
        cin >> s >> age >> weight;
        if(s=="#"&&!age&&!weight)
            break;
        cout <<s<<' ';
        if(age>17||weight>=80)
            cout << "Senior\n";
        else
            cout << "Junior\n";
    }    
    return 0;
    
}