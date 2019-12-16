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
typedef pair<int, int> pr;
typedef unordered_map<int, int> ump;

int main() {
    FASTER;
    int T, n;
    cin >> T;
    map<char, int> mp;
    while (T--) {
        mp.clear();
        cin >> n;
        char s[n];
        int in[n];
        int dist[n];
        bool all = true;
        for (int t=0;t<n;t++) {
            cin >> s[t];
            ++mp[s[t]];
            dist[t] = 0;
            in[t] = 0;
        }
        for (int t=0;t<n;t++) {
            --mp[s[t]];

            if (mp[s[t]])
                in[t] = 1;
            else
                in[t] = 0;

            if (in[t] == 1)
                all = false;
        }
        int min_ = INT_MAX;
        for (int t=0;t<n;t++) {
            for (int j=t+1;j<n;j++) {
                if (s[t] == s[j]) {
                    dist[t] = j - t;
                    if (dist[t] < min_)
                        min_ = dist[t];
                    break;
                }
            }
        }
        if (all)
            cout << 0 << '\n';
        else
            cout << (n - min_) << '\n';
    }
}
