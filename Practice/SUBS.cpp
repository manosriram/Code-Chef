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
int dp[10000][8000];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    int T, n, k;
    cin >> T;
    map<int, int> mp;
    set<int> ss;
    while (T--) {
        mp.clear();
        cin >> n >> k;
        int a[n];
        for (int t=0;t<n;++t) {
            cin >> a[t];
            ++mp[a[t]];
        }
        memset(dp, 0, sizeof(dp));
        vi grps;
        for (auto tt: mp)
            grps.pb(tt.second);

        for (int t=0;t<grps.size();++t) dp[0][t] = grps[t];

        for (int t=1;t<grps.size();++t) {
            dp[t][0] = 1;
            for (int j=t;j<k;++j) {
                    dp[t][j] = dp[t-1][j] + (dp[t-1][j-1] * (grps[t]));
            }
        }

        for (int t=0;t<k;++t) {
            for (int j=0;j<grps.size();++j) {
                cout << dp[t][j] << " ";
            }
            cout << endl;
        }
    }


#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
