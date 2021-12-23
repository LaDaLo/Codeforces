#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

struct node {
    int val, type;
    node() {}
    node(int val, int type)
    : val(val), type(type) {}

    bool compare(const node& other) const {
        if (type == 0) {
            return (other.type == 1 ? true : false);
        }
        else if (type == 1) {
            return (other.type == 2 ? true : false);
        }
        else {
            return (other.type == 0 ? true : false);
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<node> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i].val;
        a[i].type = i;
    }

    for (int i = 0; i < 3; i++) {
        cin >> b[i].val;
        b[i].type = i;
    }

    vector<vector<node>> A = {
        {a[0], a[1], a[2]},
        {a[0], a[2], a[1]},
        {a[1], a[0], a[2]},
        {a[1], a[2], a[0]},
        {a[2], a[0], a[1]},
        {a[2], a[1], a[0]}
    };

    vector<vector<node>> B = {
        {b[0], b[1], b[2]},
        {b[0], b[2], b[1]},
        {b[1], b[0], b[2]},
        {b[1], b[2], b[0]},
        {b[2], b[0], b[1]},
        {b[2], b[1], b[0]}
    };

    auto cal = [](vector<node> a, vector<node> b) {
        int i = 0, j = 0, res = 0;
        while (i < 3 && j < 3) {
            if (a[i].compare(b[j])) {
                res += min(a[i].val, b[j].val);
            }

            if (a[i].val > b[j].val) {
                a[i].val -= b[j].val;
                b[j].val = 0;
            }
            else {
                b[j].val -= a[i].val;
                a[i].val = 0;
            }

            if (a[i].val == 0) i++;
            if (b[j].val == 0) j++;
        }
        return res;
    };

    //cout << cal({a[0], a[1], a[2]}, {b[2], b[0], b[1]});

    int mn = INT_MAX, mx = INT_MIN;
    for (auto& v1 : A) {
        for (auto& v2 : B) {
            int tmp = cal(v1, v2);
            mn = min(mn, tmp);
            mx = max(mx, tmp);
        }   
    }
    cout << mn << " " << mx << "\n";
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