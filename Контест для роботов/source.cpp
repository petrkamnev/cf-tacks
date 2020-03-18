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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    int oa = 0, ob = 0, ab = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] && b[i]) ab++;
        else if (a[i]) oa++;
        else if (b[i]) ob++;
    }
    if (oa == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < 1000; i++) {
        if (i * oa > ob) {
            cout << i;
            return 0;
        }
    }
}
