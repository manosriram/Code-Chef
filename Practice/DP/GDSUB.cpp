#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    ll T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        ll a[n];
        for (ll t=0;t<n;++t) cin >> a[t];

        cout << ct << endl;
    }



#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
