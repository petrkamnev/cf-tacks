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

bool ch(int k) {
    int i = 0;
    set<int> st;
    while (k > 0) {
        st.insert(k % 10);
        k /= 10;
        i++;
    }
    return i == st.size();
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> arr(h, vector<bool>(w, 0));
    vector<int> r(h), c(w);
    for (auto &i : r) cin >> i;
    for (auto &i : c) cin >> i;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < r[i]; j++) arr[i][j] = 1;
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < c[i]; j++) arr[j][i] = 1;
    }
    vector<int> r2(h, 0), c2(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w && arr[i][j] == 1; j++) r2[i]++;
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h && arr[j][i] == 1; j++) c2[i]++;
    }
    if (r2 != r || c2 != c) {
        cout << 0;
        return 0;
    }
    int counter = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i > c[j] && j > r[i]) counter++;
        }
    }
    int k = 1;
    for (int i = 0; i < counter; i++) {
        k = (k * 2) % (int) (1e9 + 7);
    }
    cout << k;
}
