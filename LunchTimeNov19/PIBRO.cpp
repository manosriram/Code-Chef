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
#define mp make_pair
#define pb push_back
#define ld long long int
typedef vector<int> vi;
typedef pair<int, int> pr;
typedef map<int, int> mp;
typedef unordered_map<int, int> ump;

int Kadane(string s, int n) {
    int maxC = INT_MIN, ct = 0;
    for (int t=0;t<n;t++) {
        if (ct < 0)
            ct = 0;

        if (s[t] == '1')
            ++ct;
        else
            ct = 0;

        if (ct > maxC) {
            maxC = ct;
        }
    }
    return maxC;
}

int main() {
    // freopen("in.txt", "r", stdin);
    FASTER;
    string s;
    int T, n, k;
    cin >> T;

    while (T--) {
        cin >> n >> k;
        cin >> s;
        int ct = 0, maxC = INT_MIN;
        int st, ed;

        for (int t=0;t<n;t++) {
            if (ct < 0)
                ct = 0;

            if (s[t] == '1')
                ++ct;
            else
                ct = 0;

            if (ct > maxC) {
                maxC = ct;
                ed = t;
            }
        }
        st = ed - maxC + 1;

        int in = 0;
        int maxC1 = 0, maxC2 = 0;
        string s1 = s, s2 = s;
        while (k-- && ((st - in >= 0) || (ed + in < n))) {
            ++in;
            if (st - in > 0)
                s1[st-in] = '1';
            if (ed + in < n)
                s2[ed + in] = '1';

        }
        cout << max(Kadane(s1, n), Kadane(s2, n)) << '\n';
    }


}

