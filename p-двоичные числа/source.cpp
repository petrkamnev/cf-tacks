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

int get(vector<int> &st, int d) {
    int c = 0;
    while (d != 0) {
        int k = *lower_bound(st.rbegin(), st.rend(), d);
        d -= k;
        c++;
    }
    return c;
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    vector<int> st(32, -1);
    for (int i = 1; i < 32; i++) st[i] = st[i - 1] * 2;
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= 1000; i++) {
        int d = n - p * i;
        if (d <= 0) break;
        d *= -1;
        int tmp = get(st, d);
        if (abs(d) >= tmp && i >= tmp) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1;
}
