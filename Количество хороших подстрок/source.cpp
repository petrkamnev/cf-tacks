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

long long INF = 1e18;
long double EPS = 1e-8;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<int> degs(30);
    int k = 1;
    for (int i = 0; i < 30; i++) {
        degs[i] = k;
        k *= 2;
    }
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int n = s.size();
        int counter = 0;
        for (int r = n; r > 0; r--) {
            int l = r;
            int sum = 0;
            while (l > 0 && sum < n + 1) {
                sum += degs[min(29, r - l)] * (s[l - 1] - '0');
                if (sum == r - l + 1) counter++;
                l--;
                if (sum < r - l && r - l >= 20) break;
                if (sum - r + l > n + 1) break;
            }
        }
        cout << counter << endl;
    }
}
