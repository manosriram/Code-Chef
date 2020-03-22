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
#include <time.h>
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

bool ok(string s, int in) {
    if (in == 0) return true;
    if (s[in] == s[in-1]) return false;
    if (s[in] == 'L' && s[in-1] == 'R') return false;
    if (s[in] == 'R' && s[in-1] == 'L') return false;
    if (s[in] == 'U' && s[in-1] == 'D') return false;
    if (s[in] == 'D' && s[in-1] == 'U') return false;

    return true;
}
int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    int T, n;
    cin >> T;
    string s;
    while (T--) {
        cin >> n >> s;
        pair<int, int> g;
        g.first = g.second = 0;
        for (int t=0;t<n;++t) {
            if (ok(s, t)) {
                if (s[t] == 'L')
                    g.first--;
                else if (s[t] == 'R') g.first++;
                else if (s[t] == 'U') g.second++;
                else g.second--;
            }
        }
        cout << g.first << " " << g.second << endl;
    }


#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
