#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    fast_io;

    int N;
    cin >> N;
    vector<pair<long double, int>> A(N);

    function<long double(int, int)> cal = [&](long double x, long double y) -> long double {
        if (x == 0)
            return (y < 0 ? -M_PI_2 : M_PI_2);
        if (y == 0)
            return (x < 0 ? M_PI : 0.0);
        
        return (long double)atan2(y, x);
    };

    for (int i = 0; i < N; ++i) {
        long double x, y; cin >> x >> y;
        A[i].first = cal(x, y);
        A[i].second = i + 1;
    }

    sort(A.begin(), A.end());
    long double angle = M_PI + 1;
    pair<int, int> res;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1].first - A[i].first < angle) {
            angle = A[i + 1].first - A[i].first;
            res.first = A[i].second;
            res.second = A[i + 1].second;
        }
    }

    if (A[0].first < 0 && A[N - 1].first > 0 && (A[0].first + M_PI * 2 - A[N - 1].first < angle)) {
        res.first = A[0].second;
        res.second = A[N - 1].second;
    }

    cout << res.first << " " << res.second << "\n";
}