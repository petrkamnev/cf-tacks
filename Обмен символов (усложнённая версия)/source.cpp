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
double EPS = 1e-12;

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<set<int>> p1(26), p2(26);
        for (int j = n - 1; j >= 0; j--) {
            p1[s[j] - 'a'].insert(j);
            p2[t[j] - 'a'].insert(j);
        }
        bool breaker = 0;
        for (int j = 0; j < 26; j++) {
            if ((p1[j].size() + p2[j].size()) % 2 != 0) {
                cout << "No" << endl;
                breaker = 1;
                break;
            }
        }
        if (breaker) continue;
        queue<pair<int, int>> ans;
        for (int j = 0; j < n; j++) {
            if (s[j] == t[j]) {
                p1[s[j] - 'a'].erase(p1[s[j] - 'a'].begin());
                p2[s[j] - 'a'].erase(p2[s[j] - 'a'].begin());
            }
            if (s[j] != t[j]) {
                p2[t[j] - 'a'].erase(p2[t[j] - 'a'].begin());
                if (!empty(p2[t[j] - 'a'])) {
                    int tmp = *p2[t[j] - 'a'].begin();
                    p2[t[j] - 'a'].erase(p2[t[j] - 'a'].begin());
                    p1[s[j] - 'a'].erase(p1[s[j] - 'a'].begin());
                    p2[s[j] - 'a'].insert(tmp);
                    ans.push({j + 1, tmp + 1});
                    t[tmp] = s[j];
                } else {
                    p1[s[j] - 'a'].erase(p1[s[j] - 'a'].begin());
                    int tmp = *p1[t[j] - 'a'].begin();
                    p1[t[j] - 'a'].erase(p1[t[j] - 'a'].begin());
                    ans.push({tmp + 1, j + 2});
                    ans.push({j + 1, j + 2});
                    p1[t[j + 1] - 'a'].insert(tmp);
                    p2[t[j + 1] - 'a'].erase(p2[t[j + 1] - 'a'].begin());
                    p2[s[j] - 'a'].insert(j + 1);
                    s[tmp] = t[j + 1];
                    t[j + 1] = s[j];
                }
            }
        }
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.front().first << " " << ans.front().second << endl;
            ans.pop();
        }
    }
}
