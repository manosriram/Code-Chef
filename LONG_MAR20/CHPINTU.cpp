#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>
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
    ll T;
    cin >> T;
    map<int, int> mp;
    while (T--) {
        mp.clear();
        ll n, m;
        cin >> n >> m;
        int f[n], p[n];
        for (int t=0;t<n;++t) cin >> f[t];

        for (int t=0;t<n;++t) cin >> p[t];

        for (int t=0;t<n;++t)
            mp[f[t]] += p[t];

        int min_ = INT_MAX;
        for (auto t: mp)
            min_ = min(min_, t.second);

        cout << min_ << "\n";
    }
}
