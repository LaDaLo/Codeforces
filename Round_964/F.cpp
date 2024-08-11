#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int64_t MOD = 1'000'000'007;

int64_t fast_power(int64_t n, int64_t k) {
    int64_t ans = 1, cur = n;

    while (k) {
        if (k % 2 == 1) {
            ans = (ans * cur) % MOD;
        }
        k /= 2;
        cur = (cur * cur) % MOD;
    }

    return ans;
}

int64_t C(int64_t n, int64_t k, vector<int64_t> &fact) {
    return (fact[n] * fast_power((fact[k] * fact[n - k]) % MOD, MOD - 2)) % MOD;
}

int main()
{
    fast_io;
////////////////////// CODE HERE /////////////////////////////
    int t;
    cin >> t;
    while (t--) {
        int n, k, number;
        cin >> n >> k;

        int number_of_one = 0;
        for (int i = 0; i < n; ++i) {
            cin >> number;
            if (number == 1) {
                number_of_one += 1;
            }
        }
        int number_of_zero = n - number_of_one;
        int64_t ans = 0;
        // ways to choose 1
        // tu so
        if (number_of_one < k / 2 + 1) {
            cout << 0 << '\n';
            continue;
        }
        // pre compute
        vector<int64_t> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i ) % MOD;
        }

        for (int i = max(k / 2 + 1, k - number_of_zero); i <= min(number_of_one, k); ++i) {
            ans = (ans + (C(number_of_one, i, fact) * C(number_of_zero, k - i, fact) ) % MOD) % MOD;
        }
        
        cout << ans << '\n';
    }
/////////////////////////////////////////////////////////////
    return 0;
}