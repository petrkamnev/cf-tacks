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

using namespace std;

int main() {
    freopen("sweets.in", "r", stdin);
    freopen("sweets.out", "w", stdout);
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<long long> best = {0, 0, 0};
    for (int i = 0; i < 6; i++) {
        if (i == 1) {
            swap(b, c);
            swap(best[1], best[2]);
        }
        if (i == 2) {
            swap(a, b);
            swap(best[0], best[1]);
        }
        if (i == 3) {
            swap(b, c);
            swap(best[1], best[2]);
        }
        if (i == 4) {
            swap(a, b);
            swap(best[0], best[1]);
        }
        if (i == 5) {
            swap(b, c);
            swap(best[1], best[2]);
        }
        for (long long i = max(n / 3 / a - 1000, (long long) 0); i <= min((n / 3 / a) + 1000, n / a); i++) {
            long long nwoa = n - i * a;
            for (long long j = (nwoa / 2 / b) - 1000; j <= min((nwoa / 2 / b) + 1000, nwoa / b); j++) {
                if (i > 0 && j > 0 && i * a + j * b - n < 0) {
                    long long k = (nwoa - j * b) / c;
                    if (k > 0) {
                        if ((long double) i * (long double) j * (long double) k -
                            (long double) best[0] * (long double) best[1] * (long double) best[2] > 0) {
                            best = {i, j, k};
                        }
                    }
                }
            }
        }
    }
    swap(best[0], best[1]);
    swap(a, b);
    cout << best[0] * a << " " << best[1] * b << " " << best[2] * c;
}
