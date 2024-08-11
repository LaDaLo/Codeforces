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
        int l = 1, r = 999, return_value;

        while (r - l > 2) {
            int a = (2 * l + r) / 3;
            int b = (l + 2 * r) / 3;

            cout << "? " << a << " " << b << endl;
            cin >> return_value;

            if (return_value == (a + 1) * (b + 1)) {
                r = a;
            }
            else if (return_value == a * b) {
                l = b;
            }
            else {
                l = a;
                r = b;
            }
        }

        if (r - l == 2) {
            cout << "? " << 1  << " " << l + 1 << endl;
            cin >> return_value;
            if (return_value == l + 2) {
                r = l + 1;
            }
        }

        cout << "! " << r <<  endl;
    }
/////////////////////////////////////////////////////////////
    return 0;
}