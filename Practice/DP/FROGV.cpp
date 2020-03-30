// g++ -std=c++17 FROGV.cpp -o a.out && ./a.out < in
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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    vi gr;
    int tm;
    int n, k, p, l, r;
    cin >> n >> k >> p;
    int dist[n];
    vector<pair<int, int>> vc;
    for (int t=0;t<n;++t) {
        cin >> tm;
        vc.pb(make_pair(tm, t));
    }

    sort(vc.begin(), vc.end());

    dist[vc[n-1].second] = -1;
    for (int t=n-2;t>=0;--t) {
        if (vc[t+1].first - vc[t].first <= k) {
            if (dist[vc[t+1].second] != -1) dist[vc[t].second] = dist[vc[t+1].second];
            else {
                dist[vc[t].second] = vc[t+1].second + 1;
                dist[vc[t+1].second] = vc[t+1].second+1;
            }
        } else dist[vc[t].second] = -1;
    }

    while (p--) {
        cin >> l >> r;
        --l, --r;
        if (dist[vc[l].second] == dist[vc[r].second]) cout << "Yes\n";
        else cout << "No\n";
    }


#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
