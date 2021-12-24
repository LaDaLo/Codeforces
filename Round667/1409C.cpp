#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int n, x , y;
    cin >> n >> x >> y;

    int diff = y - x, dist = INT_MAX;
    for (int i = 1; i <= 59; i++) {
        if (diff % i == 0 && (diff / i + 1) <= n ) {
            dist = min(dist, i);
        }
    }

    n -= diff / dist + 1;
    int start = x, end = y;
    if (n > 0) {
        int use = min((x - 1) / dist, n);
        start = x - use * dist;
        n -= use;
    } 

    if (n > 0) {
        end = y + n * dist;
    }

    for (int i = start; i <= end; i += dist) {
        cout << i << " ";
    }
    cout << "\n";
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