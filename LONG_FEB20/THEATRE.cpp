#include <iostream>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <float.h>
#include <limits.h>
#include <stack>
#include <queue>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    freopen("in.txt", "r", stdin);
    ll T, n, t, total = 0;
    vector<ll> pf;
    int costs[] = {100, 75, 50, 25};
    int times = 4;
    char m;

    cin >> T;
    ll mt[4][4];
    while (T--) {
        cin >> n;
        pf.clear();

        for (int t=0;t<4;++t)
            for (int j=0;j<4;++j)
                mt[t][j] = 0;

        while (n--) {
            cin >> m >> t;
            mt[m - 'A'][(t/3)-1]++;
        }
        int rowFill[4], colFill[4];
        int rw, cl, max_;
        memset(rowFill, false, sizeof(rowFill));
        memset(colFill, false, sizeof(colFill));

        for (int tm = 0;tm<times;++tm) {
            max_ = INT_MIN;
            for (int t=0;t<times;++t) {
                for (int j=0;j<times;++j) {
                    if (!rowFill[t] && !colFill[j]) {
                        if (mt[t][j] > max_) {
                            max_ = mt[t][j];
                            rw = t;
                            cl = j;
                        }
                    }
                }
            }
            rowFill[rw] = true;
            colFill[cl] = true;
            pf.pb(max_);
        }
        sort(pf.begin(), pf.end(), greater<int>());
        ll prf = 0;
        int pIn = 0;

        for (int t=0;t<4;++t) {
            if (pf[t] == 0)
                prf -= 100;
            else {
                prf += pf[t] * costs[pIn];
                pIn++;
            }
        }
        cout << prf << '\n';
        total += prf;
    }
    cout << total << '\n';
}
