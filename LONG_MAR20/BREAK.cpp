#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include "unordered_map"
#define F first
#define S second
#define ll long long int
#define pb push_back
#define debug cout << "hi" << '\n';
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    ll T, n, s;
    cin >> T >> s;
    map<ll, ll> mp;
    while (T--) {
        mp.clear();
        cin >> n;
        ll a[n], b[n];
        for (ll t=0;t<n;++t) cin >> a[t];
        for (ll t=0;t<n;++t) cin >> b[t];

        sort(a, a+n);
        sort(b, b+n);
        bool can = true;
        mp[a[0]]++;
        mp[b[0]]++;
        if (b[0] <= a[0])
            can = false;

        for (ll t=1;t<n;++t) {
            if (b[t] <= a[t] || !mp[a[t]]) {
                can = false;
                break;
            }
            ++mp[a[t]];
            ++mp[b[t]];
        }
        if (can)
            cout << "YES";
        else
            cout << "NO";

        cout << '\n';
    }

}
