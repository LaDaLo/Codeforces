#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1000000007;

int64_t fast_pow(int64_t a, int64_t n) {
    int64_t res = 1;
    while (n) {
        if (n % 2)
            res = (res * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}

int64_t add(int64_t a, int64_t b) {
    return (a + b) % mod;
}

int64_t mul(int64_t a, int64_t b) {
    return (a * b) % mod;
}

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int64_t res = 0;
    int64_t Q = count(s.begin(), s.end(), '?');
    int64_t A = count(s.begin(), s.end(), 'a');
    int64_t C = count(s.begin(), s.end(), 'c');
    int64_t ca = 0, cc = 0, cq = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'a') ca++;
        else if (s[i] == 'c') cc++;
        else if (s[i] == 'b') {
            res = add(res, mul(ca, (C - cc)) * fast_pow(3, Q));
            res = add(res, mul(ca, Q - cq) * fast_pow(3, Q - 1));
            res = add(res, mul(cq, C - cc) * fast_pow(3, Q - 1));
            res = add(res, mul(cq, Q - cq) * fast_pow(3, Q - 2));
        } 
        else {
            res = add(res, mul(ca, (C - cc)) * fast_pow(3, Q - 1));
            res = add(res, mul(ca, Q - cq - 1) * fast_pow(3, Q - 2));
            res = add(res, mul(cq, C - cc) * fast_pow(3, Q - 2));
            res = add(res, mul(cq, Q - cq - 1) * fast_pow(3, Q - 3));
            cq++;
        }
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