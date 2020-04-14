#include <iostream>
#include <math.h>
#include <vector>
#define ll long long
using namespace std;

int main() {
    // freopen("out", "w", stdout);
    ll T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        ll tt = 1;

        if (n > 1) tt = floor((double)n/2);
        cout << tt << '\n';
        if (n >= 3) {
            cout << 3 << " ";
            for (int t=1;t<3;++t) cout << t << " ";

            cout << 3;
            cout << '\n';
        } else {
            cout << n << " ";
            for (int t=1;t<n;++t) cout << t << " ";

            cout << n << '\n';
            continue;
        }

        for (int t=4;t<=n;++t) {
            if ((t - 1) & 1) cout << 2 - (t == n) << " ";
            cout << t;
            if (!(t & 1) && t != n) cout << " ";

            if (t & 1)
                cout << '\n';
        }
        cout << '\n';
    }
}

