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
#define ll long long int
typedef vector<ll> vi;
typedef pair<ll,int> pi;

int main() {
    clock_t tStart = clock();
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    unordered_map<ll, bool> mp;
    ll T, n, k, ct, max_, lim;
    cin >> T;
    while (T--) {
        ct = 1, max_ = INT_MIN;
        mp.clear();
        cin >> n >> k;
        lim = k - 1;
        ll a[n];
        for (ll t=0;t<n;++t) cin >> a[t];

        int in = 0;
        for (ll t=0;t<n-1;++t) {
            mp[a[t]] = true, mp[a[t+1]] = true;

            if (mp.size() > lim) {
                mp.clear();
                max_ = max(ct, max_);
                ct = 1;
                t = ++in;
                continue;
            }
            ++ct;
        }
        max_ = max(ct, max_);
        cout << max_ << '\n';
    }


    // cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
