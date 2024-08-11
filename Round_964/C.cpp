#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    fast_io;
////////////////////// CODE HERE /////////////////////////////
    int t;
    cin >> t;
    while (t--) {
        int n, s, m, l, r, start = 0;
        bool ans = false;
        cin >> n >> s >> m;
        while (n--) {
            cin >> l >> r;

            if (l - start >= s) {
                ans = true;
            }
            
            start = r;
        }
        if (m - start >= s) {
            ans = true;
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
/////////////////////////////////////////////////////////////
    return 0;
}