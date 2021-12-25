#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1000000007;
void solve() {
    string X;
    cin >> X;

    int sum = 0, cur = 0;
    for (auto& c : X) sum += (c - '0');

    string res;
    for (int i = X.length() - 1;; i--) {
        cur += sum;
        res.push_back('0' + (cur % 10));
        cur /= 10;
        if (i >= 0) sum -= (X[i] - '0');
        if (i <= 0 && cur == 0) break;
    }
    reverse(res.begin(), res.end());
    cout << res;
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