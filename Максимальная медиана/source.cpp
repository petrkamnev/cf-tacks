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

using namespace std;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    long long n, k;
    cin >> n >> k;
    long long t = n / 2;
    vector<long long> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    long long l = -2e9, r = 1e10;
    while (l + 1 != r) {
        long long m = (l + r) / 2;
        long long s = 0;
        for (long long i = t; i < n; i++) {
            if (m - arr[i] > 0) s += m - arr[i];
        }
        if (s <= k) l = m;
        else r = m;
    }
    cout << l;
}
