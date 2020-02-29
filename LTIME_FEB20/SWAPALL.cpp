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

bool isPerm(string s, int n) {
    int a[26], ct = 0;
    memset(a, -1, sizeof(a));
    for (int t=0;t<n;++t) {
        if (a[s[t] - 'a'] == -1) a[s[t] - 'a'] = 1;
        else a[s[t] - 'a'] = -1;
    }

    for (int t=0;t<n;++t) {
        if (a[t] == 1) ++ct;
    }

    if (n % 2 != 0)
        return ct == 1;
    else
        return ct == 0;
}

int main() {
    clock_t tStart = clock();
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n >> s;

        if (!isPerm(s, n))
            cout << "NO" << '\n';
        else {
            int low = 0, high = n - 1;
            int ct = 0;
            while (low < high) {
                if (s[low] != s[high]) ++ct;
                ++low, --high;
            }
            cout << "YES" << '\n' << ct << '\n';
        }
    }

    // cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
