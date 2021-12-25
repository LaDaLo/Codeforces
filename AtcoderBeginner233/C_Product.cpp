#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1000000007;
void solve() {
    int N;
    int64_t X;
    cin >> N >> X;

    vector<vector<int64_t>> arr(N, vector<int64_t>());
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> arr[i][j];
        }
    }

    int64_t res = 0;
    function<void(int, int64_t)> dfs = [&](int i, int64_t cur) {
        if (i == N) {
            if (cur == X) res++;
            return;
        }
        if (cur > X) return;
        for (int j = 0; j < arr[i].size(); j++) {
            dfs(i + 1, cur * arr[i][j]);
        }
    };

    dfs(0, 1);
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