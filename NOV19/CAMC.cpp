#include <iostream>
#include "unordered_map"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, n, temp, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> v[m];
        pair<int, int> p[m];

        for (int t=1;t<=n;t++) {
            cin >> temp;
            v[t%m].push_back(temp);
        }

        for (int t=1;t<=n;t++) {
            pair<vector<int>::iterator, vector<int>::iterator> p1 = minmax_element(v[t%m].begin(), v[t%m].end());

            p[t%m].first = *p1.first;
            p[t%m].second= *p1.second;
        }

        int diff1, diff2, diff;

        for (int t=1;t<=n;++t) {
            for (int j=t+1;j<=n;++j) {
                diff1 = min(abs(p[t%m].first - p[j%m].first), abs(p[t%m].first - p[j%m].second));
                diff2 = min(abs(p[t%m].second - p[j%m].first), abs(p[t%m].second - p[j%m].second));
                diff = min(diff1, diff2);
            }
        }
        cout << diff << '\n';
    }
}
