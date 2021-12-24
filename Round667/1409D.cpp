#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    uint64_t n;
    int s;
    cin >> n >> s;
    auto digit = [](uint64_t n) {
        vector<int> res;
        while (n) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    };

    vector<int> cur = digit(n);
    int sum = accumulate(cur.begin(), cur.end(), 0);
    bool large = true;
    for (int i = 0; i < cur.size(); i++) {
        if (sum <= s && large)
            break;
        
        if (sum < s) {
            while (i < cur.size() && cur[i] == 9) {
                cur[i] = 0;
                i++;
            }

            if (i < cur.size()) cur[i]++;
            else cur.push_back(1);

            break;
        }

        large = false;
        sum -= cur[i];
        cur[i] = 0;
    }

    if (cur.back() == 0) cur.push_back(1);

    uint64_t next = 0;
    for (int i = cur.size() - 1; i >= 0; i--) {
        next = next * 10 + (uint64_t)cur[i];
    }
    cout << next - n << "\n";
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