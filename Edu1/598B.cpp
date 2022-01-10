#include <iostream>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
  
int main()
{
    fast_io;

    string S;
    int M;
    cin >> S >> M;
    int l, r, k;
    while (M--) {
        cin >> l >> r >> k;
        k %= (r - l + 1);
        string tmp = S.substr(r - k, k) + S.substr(l - 1, r - l + 1 - k);
        for (int i = l - 1; i <= r - 1; i++) {
            S[i] = tmp[i - l + 1];
        }
    }

    cout << S;
}