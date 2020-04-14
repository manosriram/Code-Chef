#include <iostream>
#define MOD 1000000007
using namespace std;

bool does(long long n) {
    return (n % 2 != 0 || n % 4 == 0);
}

int main() {
    long long T, n;
    cin >> T;
    while (T--) {
        long long ct = 0;
        cin >> n;
        long long a[n];
        for (long long t=0;t<n;++t) {
            cin >> a[t];
            if (does(a[t])) ++ct;
        }

        for (long long t=0;t<n;++t) {
            long long prod = a[t];
            for (long long j=t+1;j<n;++j) {
                prod = (prod * a[j]);
                cout << prod << " ";
                if (does(prod)) {
                    ++ct;
                }
            }
        }
        cout << ct << '\n';
    }
}
#include <iostream>
#include <algorithm>
#include <math.h>
#define ll unsigned long long
using namespace std;

ll sm(ll x) {
    return ((x * (x + 1)) / 2);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        ll a[n+1];
        for (ll t=0;t<n;++t) cin >> a[t];
        ll ctr = 0, aa = -1, bb = 0;
        ll ts[n], fr[n], tc=0, fc=0;
        for (ll t=0;t<n;++t) {
            if (a[t] % 2 == 1) {
                ++bb;
            } else {
                ctr += sm(bb);
                bb = 0;
                if (a[t] % 4 == 0) {
                    ll nn = (t - aa - 1) * (n - t - 1);
                    ctr += n + nn - aa;
                    --ctr;
                    aa = t;
                    fr[fc++] = t;
                } else {
                    ts[tc++] = t;
                }
            }
        }
        ctr += sm(bb);
        ll lnts=tc;
        if (lnts > 1) {
            ll lnfs=fc, tm=fr[lnfs-1];
            for (ll t=fc;t>0;--t) {
                fr[t] = fr[t-1];
            }
            fr[0] = -1;
            ++lnfs;
            fr[lnfs++] = n;
            ll gm = fr[0], ep = ts[0], dt=-1, zt=-1, t=1, j=1;
            while (t<lnfs) {
                dt = fr[t];
                if (dt < ep) {
                    gm = dt;
                } else {
                    while (j < lnts) {
                        zt = ts[j];
                        if (dt < zt) {
                            ep = zt;
                            gm = dt;
                            ++j;
                            break;
                        } else {
                            ctr += (ep * dt + gm*zt) - (ep*zt+dt*gm);
                            gm = ep;
                            ep = zt;
                            ++j;
                        }
                    }
                }
                ++t;
            }
        }
        cout << ctr << '\n';
    }
}
