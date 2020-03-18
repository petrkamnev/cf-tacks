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

bool ch(long long x) {
    for (long long i = 2; i <= (long long) (sqrt(x) + 1e-5); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

long long deg(long long n, long long k) {
    long long n0 = n;
    if (k == 0) return 1;
    long long now = 1;
    while (now * 2 <= k) {
        n = (n * n) % (long long) (1e9 + 7);
        now *= 2;
    }
    n = (n * (deg(n0, k - now))) % (long long) (1e9 + 7);
    return n;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    long long x, n;
    cin >> x >> n;
    long long ans = 1;
    set<long long> arr1;
    for (long long i = 2; i <= (long long) (sqrt(x) + 1e-5); i++) {
        if (x % i == 0) {
            arr1.insert(i);
            if (i * i != n) arr1.insert(x / i);
        }
    }
    arr1.insert(x);
    vector<long long> arr;
    for (auto i : arr1) {
        if (ch(i)) arr.push_back(i);
    }
    for (auto i : arr) {
        long long p = i, p0 = i;
        while (p <= n) {
            long long p2 = n + 1;
            if (p <= n / p0) p2 = p * p0;
            long long k = n / p - n / p2;
            ans = (ans * (deg(p % (long long) (1e9 + 7), k))) % (long long) (1e9 + 7);
            p = p2;
        }
    }
    cout << ans;
}
