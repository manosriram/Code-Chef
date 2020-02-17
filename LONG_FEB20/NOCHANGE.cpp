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
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    freopen("in.txt", "r", stdin);
    ll T, n, p, x;
    bool notSame;
    vector<ll> a;
    cin >> T;
    while (T--) {
        a.clear();
        notSame = true;
        cin >> n >> p;
        ll dp[n];
        memset(dp, 0, sizeof(dp));

        for (ll t=0;t<n;++t) {
            cin >> x;
            a.pb(x);
        }

        for (ll t=0;t<n;++t) {
            if (p % a[t] != 0) {
                dp[t] = (p / a[t]) + 1;
                notSame = false;
                break;
            }
        }
        if (notSame) {
            cout << "NO";
        } else {
            cout << "YES ";
            for (ll t=0;t<n;++t) {
                cout << dp[t] << " ";
            }
        }
        cout << '\n';

    }
}
