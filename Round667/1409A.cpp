#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int A, B;
    cin >> A >> B;
    int d = abs(A - B);
    if (d % 10 == 0) cout << d / 10 << "\n";
    else cout << d / 10 + 1 << "\n";
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