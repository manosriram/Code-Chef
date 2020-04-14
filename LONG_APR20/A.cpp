// g++ -std=c++17 A.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl "\n"
#define pb push_back
#define rep(t, n) for (int t=0;t<(n);++t)
const unsigned int M = 1000000007;
using namespace std;

int main() {
    IOS;
    ll T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        ll a[n];
        for (ll t=0;t<n;++t) cin >> a[t];

        sort(a, a+n, greater<ll>());
        ll ss = 0;
        for (ll t=0;t<n;++t) {
            a[t] -= t;

            if (a[t] > 0)
                ss = (ss + a[t]) % M;
        }
        cout << ss << '\n';
    }
}

