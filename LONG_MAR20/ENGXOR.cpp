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
        clock_t tStart = clock();

    FASTER;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ll T, n, p, q;
    ll even, odd;
    cin >> T;
    while (T--) {
        even = 0, odd = 0;
        cin >> n >> q;
        ll a[n];
        for (ll t=0;t<n;++t) {
            cin >> a[t];

            if (__builtin_popcount(a[t]) & 1) ++odd;
            else ++even;
        }

        while (q--) {
            cin >> p;

            if (__builtin_popcount(p) & 1)
                cout << odd << " " << even;
            else
                cout << even << " " << odd;

            cout << '\n';
        }
    }
    // cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

}
