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

using namespace std;
int MOD = 1e18 + 7;
double EPS = 1e-10;
mt19937 rnd(time(0));

void build(int i, int l, int r, vector<vector<int>> &tree, vector<vector<int>> &arr) {
    if (l + 1 == r) {
        tree[i] = arr[l];
        sort(tree[i].begin(), tree[i].end());
    } else {
        int m = (l + r) / 2;
        build(i * 2 + 1, l, m, tree, arr);
        build(i * 2 + 2, m, r, tree, arr);
        tree[i].resize(tree[i * 2 + 1].size() + tree[i * 2 + 2].size());
        merge(tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(), tree[i * 2 + 2].begin(), tree[i * 2 + 2].end(),
              tree[i].begin());
    }
}

int get(int i, int l, int r, int ql, int qr, int k, vector<vector<int>> &tree) {
    if (l >= qr || r <= ql) return 0;
    if (l >= ql && r <= qr) {
        if (tree.empty()) return 0;
        int ll = -1, rr = tree[i].size();
        while (ll + 1 != rr) {
            int m = (ll + rr) / 2;
            if (tree[i][m] <= k) ll = m;
            else rr = m;
        }
        return ll + 1;
    }
    int m = (l + r) / 2;
    return get(i * 2 + 1, l, m, ql, qr, k, tree) + get(i * 2 + 2, m, r, ql, qr, k, tree);
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int k = 2;
    while (k <= 1e6) k *= 2;
    vector<vector<int>> tree(k * 2);
    vector<vector<int>> rr(k);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        rr[l].push_back(r);
    }
    build(0, 0, k, tree, rr);
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        vector<int> arr;
        arr.push_back(0);
        for (int j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        arr.push_back(1e9);
        int sum = 0;
        for (int j = 0; j < arr.size() - 1; j++) {
            sum += get(0, 0, k, arr[j] + 1, arr[j + 1], arr[j + 1] - 1, tree);
        }
        ans.push_back(n - sum);
    }
    for (auto i : ans)cout << i << '\n';
}
