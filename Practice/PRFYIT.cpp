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
#define ld long long int
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    int T;
    string s;
    cin >> T;
    vector<pair<char, int> > v;

    while (T--) {
        v.clear();
        cin >> s;
        int n = s.end() - s.begin();

        int x = 0, pts;
        while (x < n) {
            pts = 0;
            while (s[x] == s[x+1]) {
                ++pts;
                ++x;
                continue;
            }

            v.pb(make_pair(s[x], pts+1));
            ++x;
        }
        if (v.size() < 4) {
            cout << 0 << '\n';
            continue;
        }
        int ct = 0;
        int min_ = INT_MAX, sm = 0;
        int n1 = n;
        n = v.size();
        if (n&1)
            n -= 3;
        else
            n -= 2;

        int sm2 = 0;
        for (int t=0;t<n;t+=2) {
            sm += min(min_, min(v[t].second, v[t+1].second));
        }
        
        int one;
        if (n&1)
            one = 3;
        else
            one = 2;

        min_ = INT_MAX;
        for (int t=n1;t>one;t-=2)
            sm2 += min(min_, min(v[t].second, v[t-1].second));

        cout << min(sm, sm2) << '\n';
    }
}

