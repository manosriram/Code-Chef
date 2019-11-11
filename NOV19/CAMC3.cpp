#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#define li long long int
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    li T, n, m, temp, diff;
    cin >> T;
    vector<pair<li, li> > v;
    while (T--) {
        diff = LLONG_MAX;
        cin >> n >> m;
        v.clear();
        for (li t=1;t<=n;t++) {
            cin >> temp;
            //v.push_back(make_pair((t % m),temp));
            v.push_back( make_pair(temp,t%m));
        }
        sort(v.begin(), v.end());
        for (int t=0;t<n-1;t++) {
            if ((v[t].second != v[t+1].second) && (abs(v[t+1].first - v[t].first) < diff))
                diff = v[t+1].first- v[t].first;
        }
        if (diff == LLONG_MAX)
            diff = 0;

      //v.push_back(make_pair((t % m),temp));
     cout << diff << '\n';
    }
}

