#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
   cin.ignore();
    while (t--)
    {
        string n;
        int sum = 0;
        getline(cin, n);
        string tmp = "";
        int nlen = n.size();
        for (int i = 0; i < nlen; i++) {
            tmp += n[i];
            if (n[i] == ' ' || i == nlen - 1)
            {
                sum += stoi(tmp);
                tmp = "";
            }
        }
        cout << sum << '\n';
    }
}
