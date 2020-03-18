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
#define int long long
#define double long double
int MOD = 1e9 + 7;
double EPS = 1e-10;
mt19937 rnd(time(0));

int get_hash(int l, int r, vector<int> &sum, vector<int> &pw) {
    return (sum[r] - ((pw[r - l] * sum[l]) % MOD) + MOD) % MOD;
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int p = 31;
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    string s;
    cin >> s;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    int n = s.size();
    vector<int> sum(n + 1, 0);
    vector<int> sum2(n + 1, 0);
    vector<int> pw(10000);
    pw[0] = 1;
    for (int i = 1; i < 10000; i++) pw[i] = (pw[i - 1] * p) % MOD;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] * p + s[i]) % MOD;
        sum2[i + 1] = (sum2[i] * p + s[n - i - 1]) % MOD;
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= s.size(); len++) {
        for (int i = 0; i < s.size() - len + 1; i++) {
            int l = i, r = i + len;
            int h1 = get_hash(l, r, sum, pw);
            int h2 = get_hash(n - r, n - l, sum2, pw);
            //cout << l << " " << r << " " << h1 << " " << h2 << endl;
            if (h1 == h2) {
                int m = (l + r) / 2;
                dp[i][r - 1] = dp[i][m - 1] + 1;
            }
        }
    }
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ans[dp[i][j]]++;
        }
    }
    for (int i = n; i >= 1; i--) {
        ans[i - 1] = ans[i] + ans[i - 1];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
