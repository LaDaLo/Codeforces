#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int64_t N, K, val;
    cin >> N >> K;
    vector<int> p(N);

    for (int i = 0; i < N; i++) cin >> p[i];
    for (int i = 0; i < N; i++) cin >> val;

    sort(p.begin(), p.end());
    vector<int> l(N), r(N + 1);
    int prev = 0; l[0] = 1; r[N - 1] = 1;
    for (int i = 1; i < N; i++) {
        int left = p[i] - K;
        while (p[prev] < left) ++prev;
        l[i] = max((i - prev + 1), l[i - 1]);
    }
    prev = N - 1;
    for (int i = N - 2; i >= 0; i--) {
        int right = p[i] + K;
        while (p[prev] > right) --prev;
        r[i] = max((prev - i + 1), r[i + 1]);
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        res = max(res, l[i] + r[i + 1]);
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