#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1000000007;
void solve() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    unordered_map<int64_t, int> m;
    int64_t res = 0, cur = 0;
    m[0] = 1;
    for (int i = 0; i < N; i++) {
        cur += arr[i];
        if (m.count(cur - K))
            res += m[cur - K];
        m[cur]++;
    }

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