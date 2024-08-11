#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    fast_io;
////////////////////// CODE HERE /////////////////////////////
    int test;
    cin >> test;
    while (test--) {
        string s, t;
        cin >> s;
        cin >> t;

        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[idx]) {
                idx++;
            }
            else if (s[i] == '?') {
                s[i] = t[idx];
                idx++;
            }

            if (idx == t.length()) {
                break;
            }
        }

        for (auto &c : s) {
            if (c == '?') {
                c = 'a';
            }
        }

        if (idx == t.length()) {
            cout << "YES\n";
            cout << s << '\n';
        }
        else {
            cout << "NO\n";
        }

    }
/////////////////////////////////////////////////////////////
    return 0;
}