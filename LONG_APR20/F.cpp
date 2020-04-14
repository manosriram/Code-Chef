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
        int n, m, k, x;
        cin >> n >> m >> k;
        map<int, int> mm;
        vv.clear();
        for (int t=0;t<n;++t) {
            mm.clear();
            for (int j=0;j<k;++j) {
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
