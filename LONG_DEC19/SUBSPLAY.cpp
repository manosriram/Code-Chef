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

int main() {
    FASTER;
    int T, n;
    cin >> T;
    map<char, int> mp;
    while (T--) {
        mp.clear();
        cin >> n;
        string s;
        cin >> s;

        for (int t=0;t<n;t++)
            ++mp[s[t]];

        int ct = 0;
        for (int t=0;t<n;t++) {
            if (mp[s[t]] > 0) --mp[s[t]];

            if (mp[s[t]]) ++ct;
        }
        cout << ct << '\n';
    }
}
