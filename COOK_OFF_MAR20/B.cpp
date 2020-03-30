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
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n+1];
        for (int t=1;t<=n;++t) cin >> a[t];

        int mx = *max_element(a, a+n);
        int fs, ls;
        for (int t=1;t<=n;++t) {
            if (a[t] == mx) {
                fs = t;
                break;
            }
        }
        for (int t=n;t>=1;--t) {
            if (a[t] == mx) {
                ls = t;
                break;
            }
        }

        if ((ls - fs + 1) >= n/2)
            cout << 0 << '\n';
        else
            cout << ((n/2) - (ls - fs + 1)) + 1 << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif
}
