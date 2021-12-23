#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> tile(N, vector<int>(4));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> tile[i][j];
        }
    }

    if (M % 2 == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (tile[i][1] == tile[i][2]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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