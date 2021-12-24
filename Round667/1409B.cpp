#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int64_t a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    if (n >= (a + b - x - y)) cout << x * y << "\n";
    else {
        int64_t res = LLONG_MAX;
        int64_t A = a - min(a - x, n);
        int64_t B = b - (n - (a - A));
        res = min(res, A * B);

        B = b - min(b - y, n);
        A = a - (n - (b - B));
        res = min(res, A * B);
        cout << res << "\n";
    }   
}       
 
int main()
{
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}