#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int sqr = sqrt(n);

    if (sqr * sqr == n) {
        cout << sqr * 2 - 2 << "\n";
        return;
    }
    else if ((sqr + 1) * (sqr + 1) == n) {
        cout << (sqr + 1) * 2 - 2 << "\n";
    }
    else {
        if (n % sqr == 0) cout << sqr + n / sqr - 2 << "\n";
        else cout << sqr + n / sqr - 1 << "\n";
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