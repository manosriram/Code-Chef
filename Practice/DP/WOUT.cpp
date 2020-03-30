// g++ -std=c++17 cpp.cpp -o a.out && ./a.out < in
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
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    int T, n, h, l, r;
    cin >> T;
    while (T--) {
        cin >> n >> h;
        int a[n];

        for (int t=0;t<n;++t) a[t] = n;
        for (int t=0;t<n;++t) {
            cin >> l >> r;

            for (int t=l;t<=r;++t) --a[t];
        }
        reverse(a, a+n);
        int sm = 0;
        int dp[n];
        for (int t=0;t<n;++t) {
            sm += a[t];
            if (t <= h-1) dp[t] = sm;
            else dp[t] = min(dp[t-1], sm - dp[t-h]);
        }
        cout << dp[n-1] << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
