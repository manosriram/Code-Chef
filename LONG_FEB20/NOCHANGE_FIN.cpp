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
    clock_t tStart = clock();
    // freopen("in.txt", "r", stdin);
    ll T, n, p, cntO, cntT, tm;
    cin >> T;
    while (T--) {
        cin >> n >> p;
        cntO = 0, cntT = 0;

        ll a[n], lt[n];
        memset(lt, 0, sizeof(lt));
        for (ll t=0;t<n;++t) cin >> a[t];

        for (ll t = n-1;t >= 0;--t) {
            if (p % a[t] != 0) {
                lt[t] = (p / a[t]) + 1;
                ++cntO;

                break;
            }
        }
        if (!cntO) {
            tm = p;
            for (ll t=n-1;t>=0;--t) {
                if (tm > 0 && (tm % a[t] == 0)) {
                    lt[t] = (tm / a[t]) - 1;
                    tm = tm - lt[t] * a[t];
                } else {
                    ++cntT;
                    lt[t] = (tm / a[t]) + 1;

                    break;
                }
            }
        }
        if (cntO > 0 || cntT > 0) {
            cout << "YES ";
            for (ll t=0;t<n;++t) cout << lt[t] << " ";

            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    // cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
