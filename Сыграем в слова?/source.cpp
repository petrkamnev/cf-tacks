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
double EPS = 1e-12;

double logg(double a, double b) {
    return log(b) / log(a);
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pair<string, int>> o, z, oz, zo;
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            if (s[0] == '0' && s[s.size() - 1] == '0') z.push_back({s, j + 1});
            if (s[0] == '0' && s[s.size() - 1] == '1') zo.push_back({s, j + 1});
            if (s[0] == '1' && s[s.size() - 1] == '1') o.push_back({s, j + 1});
            if (s[0] == '1' && s[s.size() - 1] == '0') oz.push_back({s, j + 1});
        }
        if (!o.empty() && !z.empty() & oz.empty() && zo.empty()) {
            cout << -1 << endl;
            continue;
        }
        int tt = (oz.size() + zo.size() + 1) / 2;
        vector<int> ans;
        if (oz.size() >= tt) {
            int k = oz.size() - tt;
            map<string, bool> mp;
            for (auto j : zo) mp[j.first] = 1;
            for (auto j : oz) {
                if (k == 0) break;
                string ss = "";
                for (auto kk : j.first) ss = kk + ss;
                if (!mp[ss]) {
                    k--;
                    ans.push_back(j.second);
                }
            }
            if (k > 0) {
                cout << -1 << endl;
                continue;
            }
        } else {
            int k = zo.size() - tt;
            map<string, bool> mp;
            for (auto j : oz) mp[j.first] = 1;
            for (auto j : zo) {
                if (k == 0) break;
                string ss = "";
                for (auto kk : j.first) ss = kk + ss;
                if (!mp[ss]) {
                    k--;
                    ans.push_back(j.second);
                }
            }
            if (k > 0) {
                cout << -1 << endl;
                continue;
            }
        }
        cout << ans.size() << endl;
        for (auto j : ans) cout << j << " ";
        cout << endl;
    }
}
