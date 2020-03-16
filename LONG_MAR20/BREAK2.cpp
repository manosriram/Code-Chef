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
    clock_t tStart = clock();
    freopen("in.txt", "r", stdin);
#endif

    ll T, s, n;
    cin >> T >> s;
    while (T--) {
        cin >> n;
        ll a[n], b[n];
        for (ll t=0;t<n;++t) cin >> a[t];
        for (ll t=0;t<n;++t) cin >> b[t];



    }

#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif
}
