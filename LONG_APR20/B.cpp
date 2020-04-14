// g++ -std=c++17 cpp.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <vector>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl "\n"
#define pb push_back
#define rep(t, n) for (int t=0;t<(n);++t)
const ll NN = 1e5+5;
using namespace std;

int main() {
    IOS;
    int T, n;
    cin >> T;
    while (T--) {
        vector<int> vv;
        vv.clear();
        cin >> n;
        int a[n];
        rep(t, n) cin >> a[t];

        rep(t, n)
            if (a[t] == 1) vv.pb(t+1);

        bool dd = true;
        for (int t=0;t<vv.size()-1;++t) {
            if (vv[t+1] - vv[t] < 6) {
                dd = false;
                break;
            }
        }
        if (dd || vv.size() == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

