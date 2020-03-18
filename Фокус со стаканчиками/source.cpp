#define _CRT_DISABLE_PERFCRIT_LOCKS

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int INF = 1e9;

struct Node {
    int y, val, size, num;
    Node *left, *right;

    Node(int x, int t) {
        num = t;
        val = x;
        y = rand();
        size = 1;
        left = nullptr;
        right = nullptr;
    }

    Node() {
        if (left) delete left;
        if (right) delete right;
    }
};

int get_size(Node *root) {
    if (!root) return 0;
    return root->size;
}

int &get_elem(Node *root, int k) {
    int s1 = get_size(root->left);
    if (s1 == k) {
        return root->val;
    } else if (k < s1) {
        return get_elem(root->left, k);
    } else {
        return get_elem(root->right, k - s1 - 1);
    }
}

int get_elem2(Node *root, int k) {
    int s1 = get_size(root->left);
    if (s1 == k) {
        return root->val;
    } else if (k < s1) {
        return get_elem(root->left, k);
    } else {
        return get_elem(root->right, k - s1 - 1);
    }
}

pair<int, int> getelem(Node *root, int k) {
    int s1 = get_size(root->left);
    if (s1 == k) {
        return {root->val, root->num};
    } else if (k < s1) {
        return getelem(root->left, k);
    } else {
        return getelem(root->right, k - s1 - 1);
    }
}

void update(Node *root) {
    if (!root) return;
    root->size = get_size(root->left) + get_size(root->right) + 1;
}

pair<Node *, Node *> split(Node *root, int key) {
    if (!root) return {nullptr, nullptr};
    int s1 = get_size(root->left);
    if (s1 >= key) {
        auto[root1, root2] = split(root->left, key);
        root->left = root2;
        update(root);
        return {root1, root};
    } else {
        auto[root1, root2] = split(root->right, key - s1 - 1);
        root->right = root1;
        update(root);
        return {root, root2};
    }
}

Node *merge(Node *root1, Node *root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    if (root1->y > root2->y) {
        root1->right = merge(root1->right, root2);
        update(root1);
        return root1;
    } else {
        root2->left = merge(root1, root2->left);
        update(root2);
        return root2;
    }
}

Node *pb(Node *root, int x, int i) {
    Node *t = new Node(x, i);
    root = merge(root, t);
    return root;
}

int next(vector<bool> &mp, int now) {
    for (int i = now; true; i++) {
        if (!mp[i]) return i;
    }
}

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void print(Node *root, vector<bool> &used, int &now) {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    if (!root) return;
    print(root->left, used, now);
    if (root->val == INF) {
        cout << now << " ";
        now = next(used, now + 1);
    } else {
        cout << root->val << " ";
    }
    print(root->right, used, now);
}

int main() {
    srand(time(0));
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n, m;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        root = pb(root, INF, i);
    }
    vector<bool> used(n + 1, 0);
    vector<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back({a, b});
    }
    reverse(q.begin(), q.end());
    for (auto i : q) {
        auto[a, b] = i;
        int &x = get_elem(root, 0);
        if ((x != a && x != INF) || (x == INF && used[a])) {
            cout << -1;
            return 0;
        }
        x = a;
        auto[root1, root23] = split(root, 1);
        auto[root2, root3] = split(root23, b - 1);
        root = merge(merge(root2, root1), root3);
        used[a] = 1;
    }
    int now = next(used, 1);
    print(root, used, now);
    return 0;
}
