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

int get(int a, vector<int> &par) {
    if (a == par[a]) return a;
    return par[a] = get(par[a], par);
}

void unite(int a, int b, vector<int> &par, vector<int> &rank, vector<int> &size) {
    a = get(a, par);
    b = get(b, par);
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
    int n, m;
    cin >> n >> m;
    vector<int> rank(n, 1), par(n), size(n, 1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> st;
    for (int v = 0; v < n; v++) {
        map<int, int> sum;
        for (auto u : g[v]) {
            if (u < v) {
                u = get(u, par);
                sum.insert({u, 0});
                sum[u]++;
            }
        }
        map<int, bool> tmp;
        for (auto i : sum) {
            if (get_size(i.first, par, size) == i.second) {
                tmp[i.first] = 1;
            }
        }
        stack<int> del;
        for (auto i : st) {
            if (!tmp[i]) {
                unite(i, v, par, rank, size);
                del.push(i);
            }
        }
        while (!del.empty()) {
            st.erase(del.top());
            del.pop();
        }
        st.insert(get(v, par));
    }
    cout << st.size() - 1;
}
