#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>
#include <random>
#include <ctime>
#include <tuple>

using namespace std;
#define int long long
#define double long double
int MOD = 1e18 + 7;
double EPS = 1e-10;
mt19937 rnd(time(0));

struct Node {
    int x, y, count, sum, size;
    Node *left, *right;
    Node(int a, int c) {
        x = a;
        count = c;
        left = nullptr;
        right = nullptr;
        y = rnd();
        sum = x * c;
        size = c;
    }
};

int getsize(Node *root) {
    if (!root) return 0;
    return root->size;
}

int getsum(Node *root) {
    if (!root) return 0;
    return root->sum;
}

void update(Node *root) {
    if (!root) return;
    root->sum = getsum(root->left) + getsum(root->right) + (root->count) * (root->x);
    root->size = getsize(root->left) + root->count + getsize(root->right);
}

Node *merge(Node *root1, Node *root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    if (root1->y > root2->y) {
        root2 = merge(root1->right, root2);
        root1->right = root2;
        update(root1);
        return root1;
    } else {
        root1 = merge(root1, root2->left);
        root2->left = root1;
        update(root2);
        return root2;
    }
}

pair<Node *, Node *> split(Node *root, int k) {
    if (!root) return {nullptr, nullptr};
    if (root->x > k) {
        auto[root1, root2] = split(root->left, k);
        root->left = root2;
        update(root);
        return {root1, root};
    } else {
        auto[root1, root2] = split(root->right, k);
        root->right = root1;
        update(root);
        return {root, root2};
    }
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n, q;
    Node *root = nullptr;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        arr[i] = h;
        auto[root12, root3] = split(root, h);
        auto[root1, root2] = split(root12, h - 1);
        if (!root2) root2 = new Node(h, 1);
        else {
            int c = root2->count;
            root2 = new Node(h, c + 1);
        }
        root = merge(merge(root1, root2), root3);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            int h = arr[p];
            auto[root12, root3] = split(root, h);
            auto[root1, root2] = split(root12, h - 1);
            arr[p] = x;
            if (root2->count == 1) {
                root = merge(root1, root3);
            } else {
                root2 = new Node(root2->x, root2->count - 1);
                root = merge(merge(root1, root2), root3);
            }
            auto[rootab, rootc] = split(root, x);
            auto[roota, rootb] = split(rootab, x - 1);
            if (!rootb) rootb = new Node(x, 1);
            else {
                int c = rootb->count;
                rootb = new Node(x, c + 1);
            }
            root = merge(merge(roota, rootb), rootc);
        } else {
            int v;
            cin >> v;
            double l = 0, r = 1e15;
            for (int j = 0; j < 100; j++) {
                double m = (l + r) / 2;
                auto[root1, root2] = split(root, (int) (m + 1e-10));
                double tmp = m * getsize(root1) - getsum(root1);
                if (tmp >= v) r = m;
                else l = m;
                root = merge(root1, root2);
            }
            cout << l << endl;
        }
    }
}
