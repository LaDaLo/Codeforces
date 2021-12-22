#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> A(N), a, b;
    vector<int> B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end(), greater<int>());
    sort(A.begin(), A.end(), greater<pair<int, int>>());
    int prev = -1, nxt = -1, i = 0, j;
    while (i < N) {
        int cur = A[i].first;
        int cnt = 0, j = i;
        while (j < N && A[j].first == cur) {
            if (A[j].second > prev) cnt++;
            nxt = max(nxt, A[j].second);
            j++;
        }
        if (cnt > 0) a.push_back({cur, cnt});
        i = j;
        prev = nxt;
    }

    i = 0;
    while (i < M) {
        int cur = B[i], j = i, cnt = 0;
        while (j < M && B[j] == cur) {
            cnt++;
            j++;
        }
        b.push_back({cur, cnt});
        i = j;
    }

    vector<int> res;
    i = 0; j = 0;
    while (true) {
        if (a[i].first > b[j].first) {
            cout << "NO";
            break;
        }
        else if (a[i].first < b[j].first) {
            cout << "YES\n";
            res.push_back(b[j].first);
            for (int it = b.size() - 1; it > j; it--) {
                for (int k = 0; k < b[it].second; k++) {
                    cout << b[it].first << " ";
                }
            }

            for (int k = 0; k < b[j].second - 1; k++) {
                cout << b[j].first << " ";
            }

            for (auto& x : res) cout << x << " ";
            break;
        }
        else {
            if (a[i].second > b[j].second) {
                cout << "NO";
                break;
            }
            else if (a[i].second < b[j].second) {
                cout << "YES\n";
                for (int k = 0; k <= a[i].second; k++) 
                    res.push_back(b[j].first);

                for (int it = b.size() - 1; it > j; it--) {
                    for (int k = 0; k < b[it].second; k++) {
                        cout << b[it].first << " ";
                    }
                }

                for (int k = 0; k < b[j].second - 1 - a[i].second; k++) {
                    cout << b[j].first << " ";
                }

                for (auto& x : res) cout << x << " ";

                break;
            }
            else {
                if (i + 1 == a.size() && j + 1 < b.size()) {
                    cout << "YES\n";
                    

                    
                    for (int k = 0; k < b[j].second; k++) {
                        res.push_back(b[j].first);
                    }

                    res.push_back(b[j + 1].first);

                    for (int it = b.size() - 1; it > j + 1; it--) {
                        for (int k = 0; k < b[it].second; k++) {
                            cout << b[it].first << " ";
                        }
                    }

                    for (int k = 0; k < b[j + 1].second - 1; k++) {
                        cout << b[j + 1].first << " ";
                    }

                    for (auto& x : res) cout << x << " ";

                    break;

                }
                else if (j + 1 == b.size()) {
                    cout << "NO";
                    break;
                }
                else {
                    
                    for (int k = 0; k < b[j].second; k++) {
                        res.push_back(b[j].first);
                    }
                    i++; j++;
                }
            }
        }
    }

    cout << "\n";
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