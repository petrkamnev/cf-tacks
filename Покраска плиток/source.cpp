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
    int n;
    cin >> n;
    bool ch = 0, nch = 0;
    for (int i = 2; i < sqrt(n) + 1e-6; i++) {
        if (n % i == 0) {
            int a = n / i;
            if (a % 2 == 0 || i % 2 == 0) ch = 1;
            if (a % 2 != 0 || i % 2 != 0) nch = 1;
        }
    }
    if (!ch && !nch) cout << n;
    else if (ch && nch) cout << 1;
    else cout << 2;
}
