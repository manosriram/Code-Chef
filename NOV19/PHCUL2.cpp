#include <iostream>
#include <iomanip>
#include <vector>
#include <float.h>
#include <math.h>
#define ld double
#define pb push_back
#define mp make_pair
using namespace std;
ld n, m, k;

ld fD(pair<ld, ld> v1, pair<ld, ld> v2) {
    return hypot(v2.first - v1.first, v2.second - v1.second);
}

ld solve(vector<pair<ld, ld> > v1, vector<pair<ld, ld> > v2, vector<pair<ld, ld> > vK, pair<ld, ld> st, bool rem) {
    if (rem)
        swap(n, m);
    ld d1, d2, d3, tMX = DBL_MAX, tFMX = DBL_MAX;
    pair<ld, ld> tP;
    for (int t=0;t<n;t++) {
        d1 = fD(st, v1[t]);

        for (int j=0;j<m;j++) {
            d2 = fD(v1[t], v2[j]);
            ld res;
            res = d1 + d2;

            if (res < tMX) {
                tMX = res;
                tP = v2[j];
            }
        }
    }

    for (int t=0;t<k;t++) {
        d3 = fD(tP, vK[t]);
        ld res;
        if (tMX < d3)
            res = tMX + d3;
        else
            res = d3 + tMX;

        if (res < tFMX)
            tFMX = res;
    }
    return tFMX;
}

int main() {
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(5);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;

    while (T--) {
        vector<pair <ld, ld> > v1, v2, vK;
        v1.clear();
        v2.clear();
        vK.clear();
        ld x, y;
        cin >> x >> y;
        cin >> n >> m >> k;

        pair<ld, ld> st(x, y);
        ld temp1, temp2;
        for (int t=0;t<n;t++) {
            cin >> temp1 >> temp2;
            v1.pb(mp(temp1, temp2));
        }

        for (int t=0;t<m;t++) {
            cin >> temp1 >> temp2;
            v2.pb(mp(temp1, temp2));
        }

        for (int t=0;t<k;t++) {
            cin >> temp1 >> temp2;
            vK.pb(mp(temp1, temp2));
        }
        printf("%.10f\n", min(solve(v1, v2,  vK, st, false), solve(v2, v1, vK, st, true)));  
    }
}
