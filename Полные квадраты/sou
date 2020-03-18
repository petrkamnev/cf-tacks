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
#include <quadmath.h>
#include <random>
#include <ctime>
#include <tuple>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    long long k;
    cin >> k;
    long long mina = 1e18, minb = 1e18;
    for (long long i = 1; i < sqrt(abs(k)) + 1; i++) {
        if (abs(k) % i == 0) {
            long long x = abs(k) / i;
            long long y = abs(k) / x;
            if (y < x) swap(x, y);
            if (x % 2 == y % 2) {
                long long a = (x + y) / 2;
                long long b = (y - x) / 2;
                mina = min(a, mina);
                minb = min(b, minb);
            }
        }
    }
    if (k > 0) {
        if (minb != 1e18) cout << mina;
        else cout << "none";
    } else if (k < 0) {
        if (mina != 1e18) cout << minb;
        else cout << "none";
    } else {
        cout << 0;
    }
}
