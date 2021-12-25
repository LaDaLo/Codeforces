#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1000000007;
void solve() {
    int X, Y;
    cin >> X >> Y;

    cout << int(ceil((max(0, Y - X)) * 1.0 / 10));
}       
 
int main()
{
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}