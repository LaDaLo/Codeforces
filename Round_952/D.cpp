#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int64_t var, q, h, s, d;
    int64_t N, count = 0;
    while (cin >> var) {
        if (count == 0) {
            q = var;
        }
        else if (count == 1) {
            h = var;
        }
        else if (count == 2) {
            s = var;
        }
        else if (count == 3) {
            d = var;
        }
        else {
            N = var;
        }
        count += 1;
    }

    int64_t x, y, z, min_1, amount, value, ans;
    x = q * 4;
    y = h * 2;
    z = s;

    if (x < y) {
        if (x < z) {
            min_1 = x;
            amount = 4;
            value = q;
        }
        else {
            min_1 = z;
            amount = 1;
            value = s;
        }
    }
    else {
        if (y < z) {
            min_1 = y;
            amount = 2;
            value = h;
        }
        else {
            min_1 = z;
            amount = 1;
            value = s;
        }
    }

    if (min_1 * 2 > d) {
        int64_t k = N / 2;
        ans += k * d;
        N -= k * 2;
        if (N != 0) {
            ans += N * amount *  value;
        }
    }
    else {
        ans += N * amount *  value;
    }
    cout << ans;
}       
 
int main()
{
    fast_io;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}