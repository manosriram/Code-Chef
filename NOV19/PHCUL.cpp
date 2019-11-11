#include <float.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
long double n, m, k;

long double fD(pair<long double, long double> v1,
        pair<long double, long double> v2) {
    return (sqrtl(pow(v2.first - v1.first, 2) +
                pow(v2.second - v1.second, 2) * 1.0));
}

long double findMD(
        vector<pair<pair<long double, long double>, long double> > v1,
        vector<pair<pair<long double, long double>, long double> > v2,
        pair<int, int> st, vector<pair<long double, long double> > vK, bool rev) {
    if (rev) swap(n, m);

    long double dist = DBL_MAX;
    pair<long double, long double> fP, sP;
    for (int t = 0; t < n; t++) {
        for (int j = 0; j < m; j++) {
            long double dt = fD(v1[t].first, v2[j].first);

            if (v1[t].second > dt) {
                v1[t].second = dt;
                fP = v1[t].first;
                sP = v2[j].first;
            }
        }
    }

    for (int t = 0; t < n; t++) {
        long double dt = fD(v1[t].first, st);
        if (v1[t].second + dt < dist) dist = v1[t].second + dt;
    }

    long double tD = DBL_MAX;
    for (int t = 0; t < k; t++) {
        long double dt = fD(sP, vK[t]);
        if (dt < tD) {
            tD = dt;
        }
    }
    dist += tD;
    return dist;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<pair<pair<long double, long double>, long double> > v1, v2;
    vector<pair<long double, long double> > vK;
    int T;
    cin >> T;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(10);
    while (T--) {
        v1.clear();
        v2.clear();
        vK.clear();
        long double x, y;
        cin >> x >> y;
        pair<long double, long double> st(x, y);
        cin >> n >> m >> k;
        long double temp1, temp2;
        for (int t = 0; t < n; t++) {
            cin >> temp1 >> temp2;
            v1.push_back(make_pair(make_pair(temp1, temp2), DBL_MAX));
        }

        for (int t = 0; t < m; t++) {
            cin >> temp1 >> temp2;
            v2.push_back(make_pair(make_pair(temp1, temp2), DBL_MAX));
        }

        for (int t = 0; t < k; t++) {
            cin >> temp1 >> temp2;
            vK.push_back(make_pair(temp1, temp2));
        }

        cout << min(findMD(v1, v2, st, vK, true), findMD(v2, v1, st, vK, false))
            << '\n';
    }
}
