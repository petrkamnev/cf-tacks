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

void build(int i, int l, int r, vector<vector<int>> &tree, vector<int> &arr) {
    if (l + 1 == r) {
        if (l < arr.size()) tree[i][arr[l]]++;
        return;
    }
    int m = (l + r) / 2;
    build(i * 2 + 1, l, m, tree, arr);
    build(i * 2 + 2, m, r, tree, arr);
    for (int j = 0; j < tree[i].size(); j++) tree[i][j] = tree[i * 2 + 1][j] + tree[i * 2 + 2][j];
}

void update(int i, int l, int r, int q, int c, vector<vector<int>> &tree) {
    if (l > q || r <= q) return;
    if (l + 1 == r) {
        tree[i][c] = 1;
        for (int j = 0; j < 26; j++) {
            if (j != c && tree[i][j] == 1) {
                tree[i][j] = 0;
                return;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, q, c, tree);
    update(i * 2 + 2, m, r, q, c, tree);
    for (int j = 0; j < tree[i].size(); j++) {
        tree[i][j] = tree[i * 2 + 1][j] + tree[i * 2 + 2][j];
    }
}

vector<int> get(int i, int l, int r, int ql, int qr, vector<vector<int>> &tree) {
    if (l >= qr || r <= ql) return vector<int>(26, 0);
    if (l >= ql && r <= qr) return tree[i];
    int m = (l + r) / 2;
    vector<int> arr1 = get(i * 2 + 1, l, m, ql, qr, tree), arr2 = get(i * 2 + 2, m, r, ql, qr, tree);
    vector<int> ans(26, 0);
    for (int j = 0; j < 26; j++) ans[j] = arr1[j] + arr2[j];
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    string s;
    cin >> s;
    int k = 1;
    vector<int> arr(s.size());
    for (int i = 0; i < s.size(); i++) arr[i] = s[i] - 'a';
    while (k < arr.size()) k *= 2;
    vector<vector<int>> tree(k * 2, vector<int>(26, 0));
    build(0, 0, k, tree, arr);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            c -= 'a';
            pos--;
            update(0, 0, k, pos, c, tree);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            vector<int> ans = get(0, 0, k, l, r, tree);
            int sum = 0;
            for (int j = 0; j < 26; j++) if (ans[j] > 0) sum++;
            cout << sum << endl;
        }
    }
}
