#include<iostream>

using namespace std;

int main() {
    int arr[4];
    for(int i=0 ;i<4;i++){
        cin >> arr[i];
    }
    
    int total = 1800;
    for(int n : arr) {
        total -=n;
    }

    if(total >= 300) {
        cout << "Yes" <<'\n';
        return 0;
    }
    cout << "No" << '\n';
    return 0;
}