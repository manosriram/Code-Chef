#include <iostream>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <float.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <time.h>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pi;
const ll md = 1000000007;

ll cnst(ll x) {
    ll cc = 0;
    while (x) {
        cc += (x & 1);
        x >>= 1;
    }
    return cc;
}

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll a[n];
        for (ll t=0;t<n;++t) cin >> a[t];

        ll ways = 1;
        for (ll t=1;t<n;++t) {
            ways *= pow(2, cnst(a[t] & a[t-1]));
            ways %= md;
        }

        cout << ways << '\n';
    }


#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
