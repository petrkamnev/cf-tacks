#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <cstring>

using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0)

void dfs(int start, vector<vector<int>> &g, vector<int> &mx) {
    for (auto i : g[start]) {
        dfs(i, g, mx);
        mx[start] = max(mx[start], mx[i] + 1);
    }
}

signed main() {
    fastio;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    m--;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int k;
        cin >> k;
        k--;
        g[k].push_back(i);
    }
    vector<int> mx(n, 1);
    dfs(0, g, mx);
    int mmx = mx[0];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int m1, m2;
        m1 = m2 = -1;
        for (auto j : g[i]) {
            m2 = max(m2, mx[j]);
            if (m1 < m2) swap(m1, m2);
        }
        if (m2 == -1) {
            ans = max(ans, mx[i] + mmx * m);
        } else {
            ans = max(ans, m1 + m2 + 1 + mmx * m * 2);
        }
    }
    cout << ans;
}
