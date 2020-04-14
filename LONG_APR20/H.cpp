#include <iostream>
#include <vector>
#include <algorithm>
#include "unordered_map"
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1000000007
const ll nn = 10001;
using namespace std;
vector<ll> g[nn], dst[nn];
// ll g[nn][nn], dst[nn][nn];
ll a[nn];

void sieve(ll n, bool prime[],
        bool primesquare[], ll a[])
{
    for (ll i = 2; i <= n; i++)
        prime[i] = true;

    for (ll i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
    prime[1] = false;

    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }

    ll j = 0;
    for (ll p = 2; p <= n; p++) {
        if (prime[p]) {
            a[j] = p;

            primesquare[p * p] = true;
            j++;
        }
    }
}


ll fctr(ll n) {
    if (n == 1)
        return 1;

    bool prime[n + 1], primesquare[n * n + 1];

    ll aa[n];
    sieve(n, prime, primesquare, aa);

    ll ans = 1;

    for (ll i = 0;; i++) {
        if (aa[i] * aa[i] * aa[i] > n)
            break;
        ll cnt = 1;
        while (n % aa[i] == 0) {
            n = n / aa[i];
            cnt = cnt + 1;
        }
        ans = (ans * cnt) % MOD;
    }

    if (prime[n])
        ans = ans * 2;
    else if (primesquare[n])
        ans = ans * 3;

    else if (n != 1)
        ans = ans * 4;

    ans %= MOD;
    return ans;
}

void fw(ll n) {
    for (ll t=0;t<n;++t) {
        for (ll j=0;j<n;++j) {
            if (t == j) dst[t].pb(1);
            else if (g[t][j]) dst[t].pb(a[j]);
            else dst[t].pb(10001);
        }
    }
    for (int t=0;t<n;++t) {
        for (int j=0;j<g[t].size();++j) {
            cout << g[t][j] << " ";
        }
        cout << endl;
    }
    return;
    for (ll k=0;k<n;++k) {
        for (ll t=0;t<n;++t) {
            for (ll j=0;j<n;++j) {
                dst[t][j] = min(dst[t][j], dst[t][k] * dst[k][j]);
            }
        }
    }

    for (ll t=0;t<n;++t) {
        for (ll j=0;j<n;++j) {
            dst[t][j] *= a[t];
        }
    }
    return;
}

void clear() {
    for (ll t=0;t<nn;++t) {
        for (ll j=0;j<nn;++j) {
            g[t][j] = 0;
            dst[t][j] = 0;
        }
    }    
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ll n, u, v, q, T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (ll t=0;t<n-1;++t) {
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (ll t=0;t<n;++t)
            cin >> a[t];

        fw(n);
        ll s, d;
        return 0;
        for (int t=0;t<n;++t) {
            for (int j=0;j<n;++j) {
                cout << dst[t][j] << " ";
            }
            cout << endl;
        }
        cin >> q;
        while (q--) {
            cin >> s >> d;
            --s, --d;
            cout << fctr(dst[s][d]) << endl;
        }
    }
}
