#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1000000007;
void solve() {
    int L, R;
    cin >> L >> R;
    string s;
    cin >> s;

    for (int i = 0; i < L - 1; i++) cout << s[i];
    for (int i = R - 1; i >= L - 1; i--) cout << s[i];
    for (int i = R; i < s.length(); i++) cout << s[i];
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