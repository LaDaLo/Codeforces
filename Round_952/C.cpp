#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans = 0;
    int64_t sum = 0, max = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
        if (sum == max * 2) {
            ans += 1;
        }
    }

    cout << ans << '\n';
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