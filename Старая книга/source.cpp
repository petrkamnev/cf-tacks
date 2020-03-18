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
#include <cstdint>

using namespace std;

long long nm = 0;

bool ch(long long k, long long z, long long s) {
    nm = max((int) (k + z + 1), (int) nm);
    while (true) {
        long long sum = (nm - k - z) * (k + z + 1 + nm) / 2;
        if (sum >= s) break;
        nm++;
    }
    long long sum = (nm - z - k) * (k + 1 + nm - z) / 2;
    if (sum <= s) return 1;
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    long long k, s;
    cin >> k >> s;
    int r = 0;
    while (!ch(k, r, s)) r++;
    cout << r + k;
}
