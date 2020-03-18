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
#define int long long
#define double long double
int MOD = 1e18 + 7;
double EPS = 1e-10;

int logg(double a, double b) {
    return (int) (log(b) / log(a) + 0.999999999);
}

int get(int a, vector<int> &par) {
    if (a == par[a]) return a;
    return par[a] = get(par[a], par);
}

void unite(int a, int b, vector<int> &par, vector<int> &rank, vector<int> &size) {
    a = get(a, par);
    b = get(b, par);
    if (a == b) return;
    if (rank[a] > rank[b]) {
        par[b] = a;
        size[a] += size[b];
    } else {
        if (rank[a] == rank[b]) rank[b]++;
        size[b] += size[a];
        par[a] = b;
    }
}

int get_size(int u, vector<int> &par, vector<int> &size) {
    u = get(u, par);
    return size[u];
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> vec(k);
    for (auto &i : vec) cin >> i;
    vector<int> par(n), size(n), rank(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        size[i] = 0;
        rank[i] = 1;
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (u != v) {
            mp.insert({{u, v}, 1e18});
            mp[{u, v}] = min(mp[{u, v}], w);
        }
    }
    vector<pair<int, pair<int, int>>> arr;
    for (auto i : mp) {
        arr.push_back({i.second, i.first});
    }
    sort(arr.begin(), arr.end());
    for (auto i : vec) {
        size[i - 1] = 1;
    }
    for (auto i : arr) {
        int w = i.first;
        int u = i.second.first, v = i.second.second;
        unite(u, v, par, rank, size);
        if (get_size(u, par, size) == k) {
            for (int j = 0; j < k; j++) {
                cout << w << " ";
            }
            return 0;
        }
    }
}
