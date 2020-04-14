#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> vv;
    while (T--) {
        int n, k, m, x;
        cin >> n >> m >> k;
        map<int, int> mm;
        vv.clear();
        for (int t=0;t<n;++t) {
            mm.clear();
            for (int tt=0;tt<k;++tt) {
                cin >> x;
                ++mm[x];
            }
            int mx = INT_MIN, qs;
            for (auto tt: mm) {
                if (tt.second >= mx) {
                    mx = tt.second;
                    qs = tt.first;
                }
            }
            vv.push_back(qs);
        }
        for (auto tt: vv) cout << tt << " ";

        cout << '\n';
    }
}

