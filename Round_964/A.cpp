#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    fast_io;
////////////////////// CODE HERE /////////////////////////////
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n % 10 + n / 10 << "\n";
    }
/////////////////////////////////////////////////////////////
    return 0;
}