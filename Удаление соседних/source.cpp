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
    int N;
    cin >> n;
    N = n;
    string s;
    cin >> s;
    for (char c = 'z'; c > 'a'; c--) {
        for (int I = 0; I < N; I++) {
            n = s.size();
            if (s[0] == c && 1 < n && s[1] == c - 1) {
                s[0] = (char) 0;
            }
            if (s[s.size() - 1] == c && s.size() - 2 >= 0 && s[s.size() - 2] == c - 1) {
                s[s.size() - 1] = (char) 0;
            }
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == c && (s[i - 1] == c - 1 || s[i + 1] == c - 1)) {
                    s[i] = (char) 0;
                }
            }
            string ts = "";
            for (auto j : s) if (j != (char) 0) ts = ts + j;
            swap(s, ts);
        }
    }
    cout << N - s.size();
}
