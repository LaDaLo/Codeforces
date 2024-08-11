#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 2, max = 0;

    for (int x = 2; x <= n; ++x) {
        int count = x * (n / x) * (n / x + 1) / 2;
        if (count >= max) {
            max = count;
            ans = x;
        }
    }

    cout << ans << "\n";
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