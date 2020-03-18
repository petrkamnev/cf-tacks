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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        map<int, int> mp;
        for (int j = 0; j < d; j++) {
            mp.insert({arr[j], 0});
            mp[arr[j]]++;
        }
        int mn = mp.size();
        for (int j = 1; j + d - 1 < n; j++) {
            mp[arr[j - 1]]--;
            mp.insert({arr[j + d - 1], 0});
            mp[arr[j + d - 1]]++;
            if (mp[arr[j - 1]] == 0) mp.erase(arr[j - 1]);
            mn = min(mn, (int) mp.size());
        }
        cout << mn << endl;
    }
}
