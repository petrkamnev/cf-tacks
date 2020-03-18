#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

#define int long long
#define double long double
mt19937 rnd(time(0));
int INF = 1e18;
int EPS = 1e-10;
double PI = atan2(1.0, 0.0) * 2;

signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    vector<int> c(n), b(n);
    for (auto &i : b) cin >> i;
    for (int i = 0; i < n; i++) {
        c[i] = i;
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp.insert({c[i] - b[i], 0});
        mp[c[i] - b[i]] += b[i];
    }
    int ans = 0;
    for (auto i : mp) ans = max(ans, i.second);
    cout << ans;
}
