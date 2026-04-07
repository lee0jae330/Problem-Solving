#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> preorder, inorder;

int inIdx[1001];

pair<int, int> tree[1001];
int root = -1;

// dir -1 처음, 0 left, 1 right
void buildTree(int dir, int parent, pair<int, int> pre, pair<int, int> in) {
    int r = preorder[pre.first];
    if (dir == -1) {
        root = r;
    } else if (dir == 0) {
        tree[parent].first = r;
    } else {
        tree[parent].second = r;
    }

    if (pre.first == pre.second || in.first == in.second) {
        return;
    }

    int iIdx = inIdx[r];

    pair<int, int> l_pre = {pre.first + 1, pre.first + iIdx - in.first};
    pair<int, int> r_pre = {pre.first + 1 + iIdx - in.first, pre.second};

    pair<int, int> l_in = {in.first, iIdx - 1};
    pair<int, int> r_in = {iIdx + 1, in.second};

    if (l_pre.first <= l_pre.second && l_in.first <= l_in.second) {
        buildTree(0, r, l_pre, l_in);
    }

    if (r_pre.first <= r_pre.second && r_in.first <= r_in.second) {
        buildTree(1, r, r_pre, r_in);
    }
}

void postorder(int node) {
    auto [l, r] = tree[node];
    if (l != -1) {
        postorder(l);
    }

    if (r != -1) {
        postorder(r);
    }

    cout << node << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        preorder.resize(n);
        inorder.resize(n);

        root = -1;

        for (int i = 0; i < n; i++) {
            cin >> preorder[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
            inIdx[inorder[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            tree[i].first = -1, tree[i].second = -1;
        }

        buildTree(-1, -1, {0, n - 1}, {0, n - 1});
        postorder(root);
        cout << '\n';
    }
    return 0;
}
