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
        int a, b, c, d, ans = 0;
        cin >> a >> b >> c >> d;

        int A[2] = {a, b};
        int B[2] = {c, d};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int A_first = A[i];
                int A_second = A[1 - i];
                int B_first = B[j];
                int B_second = B[1 - j];

                int point_A = 0, point_B = 0;
                if (A_first > B_first) {
                    point_A++;
                }
                if (A_second > B_second) {
                    point_A++;
                }
                if (A_first < B_first) {
                    point_B++;
                }
                if (A_second < B_second) {
                    point_B++;
                }
                if (point_A > point_B) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
/////////////////////////////////////////////////////////////
    return 0;
}