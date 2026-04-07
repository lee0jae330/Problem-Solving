#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> inorder, postorder;

int inorderIdx[100001];

pair<int, int> tree[100001];

int root;

void buildTree(int dir, int parent, pair<int, int> in, pair<int, int> post) {
    int r = postorder[post.second];

    if (dir == -1) {
        root = r;
    } else if (!dir) {
        tree[parent].first = r;
    } else {
        tree[parent].second = r;
    }

    int iIdx = inorderIdx[r];

    pair<int, int> l_in, r_in, l_post, r_post;

    l_in = {in.first, iIdx - 1};
    r_in = {iIdx + 1, in.second};

    l_post = {post.first, post.first + iIdx - 1 - in.first};
    r_post = {post.first + iIdx - in.first, post.second - 1};

    if (l_in.first <= l_in.second && l_post.first <= l_post.second) {
        buildTree(0, r, l_in, l_post);
    }

    if (r_in.first <= r_in.second && r_post.first <= r_post.second) {
        buildTree(1, r, r_in, r_post);
    }
}

void preorder(int node) {
    cout << node << ' ';
    auto [l, r] = tree[node];
    if (l != -1) {
        preorder(l);
    }

    if (r != -1) {
        preorder(r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i <= n; i++) {
        tree[i] = {-1, -1};
    }

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorderIdx[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    buildTree(-1, -1, {0, n - 1}, {0, n - 1});
    preorder(root);
    cout << '\n';

    return 0;
}