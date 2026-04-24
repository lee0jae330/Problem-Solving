#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int INDEX = 1e5 + 1;

int A, B, N, M;
int visited[INDEX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(visited, visited + INDEX, -1);
    cin >> A >> B >> N >> M;
    visited[N] = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int x = q.front(), tx;
        if (x == M) {
            cout << visited[x] << '\n';
            return 0;
        }
        q.pop();
        tx = x + 1;
        if (tx <= 1e5 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x - 1;
        if (tx >= 0 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x + A;
        if (tx <= 1e5 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x - A;
        if (tx >= 0 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x + B;
        if (tx <= 1e5 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x - B;
        if (tx >= 0 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x * A;
        if (tx <= 1e5 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }

        tx = x * B;
        if (tx <= 1e5 && visited[tx] == -1) {
            visited[tx] = visited[x] + 1;
            q.push(tx);
        }
    }
    return 0;
}