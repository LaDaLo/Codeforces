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
        int l, r;
        cin >> l >> r;

        int64_t ans = 0;
        int temp = l;
        while (temp) {
            ++ans;
            temp /= 3;
        }
        ans *= 2;
        l++;
        int64_t cur = 3, idx = 1;

        while (cur <= r) {
            if (l < cur) {
                ans += (cur - l) * idx;
                l = cur;
            }
            idx += 1;
            cur *= 3;
        }

        ans += (r - l + 1) * idx;

        cout << ans << '\n';
    }
/////////////////////////////////////////////////////////////
    return 0;
}