#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
#define MOD 1000000007
#define ll long long
#define pb push_back
#define MAXN 10001
using namespace std;
vector<ll> g[MAXN];
ll a[MAXN];
bool vis[MAXN] = { false };

void clear(ll n) {
    for (ll t=0;t<=n;++t) {
        vis[t] = false;
        g[t].clear();
    }
}

ll dvsrs(ll n) {
    ll ct = 0;
    for (ll t=1;t<=sqrt(n);++t) {
        if (n % t == 0) {
            if (n/t == t) ct = (ct + 1) % MOD;
            else ct = (ct + 2) % MOD;
        }
    }
    return ct;
}

ll bfs(ll s, ll d) {
    if (s == d) return a[s];
    vis[s] = true;
    queue<ll> q;
    q.push(s);
    ll prod = 1;

    while (!q.empty()) {
        ll tm = q.front();
        prod = (prod * a[tm]) % MOD;
        q.pop();

        for (auto nd: g[tm]) {
            if (nd == d) {
                prod = (prod * a[nd]) % MOD;
                return prod;
            }

            if (!vis[nd]) {
                vis[nd] = true;
                q.push(nd);
            }
        }
    }
    return 0;
}

int main() {
    ll n, u, v, q, T;
    cin >> T;
    while (T--) {
        cin >> n;
        clear(n);
        for (ll t=0;t<n-1;++t) {
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (ll t=0;t<n;++t)
            cin >> a[t];

        ll s, d;
        cin >> q;
        while (q--) {
            for (ll t=0;t<=n;++t) vis[t] = false;
            cin >> s >> d;
            --s, --d;
            ll res = bfs(s, d);
            cout << dvsrs(res) << '\n';
        }
    }
}
