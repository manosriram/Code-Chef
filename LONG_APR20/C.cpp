#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;

bool isPrime(ll n) {
    if (n == 1) return false;

    for (ll t=2;t<=sqrt(n)+1;++t)
        if (n % t == 0) return false;

    return true;
}

vector<ll> Solve(ll n) {
    vector<ll> v;
    while (n % 2 == 0) {
        v.push_back(2);
        n /= 2;
    }
    for (ll t=3;t<=sqrt(n)+1;t+=2) {
        while (n % t == 0) {
            v.push_back(t);
            n /= t;
        }
    }
    if (n > 2) v.push_back(n);
    return v;
}

int main() {
    ll T, x, k;
    cin >> T;
    while (T--) {
        cin >> x >> k;
        if (k == 1) cout << 1;
        else if (k == 2) cout << !isPrime(x);
        else {
            auto res = Solve(x);
            bool dn = false;
            if (res.size() >= k) {
                for (auto i: res) {
                    if (i <= 1) {
                        cout << 0;
                        dn = true;
                        break;
                    }
                }
                if (!dn) cout << 1;
            } else cout << 0;
        }

        cout << '\n';
    }
}

