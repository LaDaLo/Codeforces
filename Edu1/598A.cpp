#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1000000007;
void solve() {
    int64_t N;
    cin >> N;

    int64_t res = N * (N + 1) / 2, tmp = 1;
    while (tmp <= N) {
        res -= 2 * tmp;
        tmp *= 2;
    } 

    cout << res << "\n";
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