#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string s, t;
    cin >> s;
    cin >> t;

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                if (dp[i][j][k] == -1)
                    continue;
                
                if (s[i] == t[0] && s[i] == t[1]) {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + j);
                }
                else if (s[i] == t[0]) {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k]);       
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + j);
                }
                else if (s[i] == t[1]) {
                    dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + j);
                }
                else {
                    if (t[0] == t[1]) {
                        dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k] + j);
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    }
                    else {
                        dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                        dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + j);
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    }
                }     
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[N][i][j] != -1)
                res = max(res, dp[N][i][j]);
        }
    }
    cout << res << "\n";
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