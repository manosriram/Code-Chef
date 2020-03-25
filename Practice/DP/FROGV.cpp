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
#include <cstring>
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
map<pair<int, int>, bool> mp;

int dist(int sr, int dt) {
    return abs(sr - dt);
}

void Solve(int *a, int n, int k) {
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    mp[make_pair(0, 0)] = dp[0][0];

    for (int t=1;t<n;++t) {
        dp[0][t] = dp[0][t-1] && (dist(a[t], a[t-1]) <= k);
        mp[make_pair(0, t)] = dp[0][t];
    }

    for (int t=1;t<n;++t) {
        for (int j=0;j<n;++j) {
            if (t == j) {
                dp[t][j] = true;
                mp[make_pair(t, j)] = true;
                continue;
            }
            dp[t][j] = dp[t-1][j] && (dist(a[t], a[t-1]) <= k);
            mp[make_pair(t, j)] = dp[t][j];
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    vi gr;
    int n, k, p, l, r;
    cin >> n >> k >> p;
    int a[n];
    for (int t=0;t<n;++t) cin >> a[t];

    sort(a, a+n);
    Solve(a, n, k);

    while (p--) {
        cin >> l >> r;
        if (mp[make_pair(l, r)]) cout << "YES\n";
        else cout << "NO\n";
    }

#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
