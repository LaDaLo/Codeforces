#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    int res = 0;
    unordered_set<int64_t> s;
    for (int i = 1; i <= N; i++) {
        int64_t cur = arr[i];
        arr[i] += arr[i - 1];
        if (arr[i] == 0 || s.count(arr[i])) {
            res++;
            arr[i] = cur;
            s.clear();
        }
        s.insert(arr[i]);
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