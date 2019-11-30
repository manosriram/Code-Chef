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
    //freopen("in.txt", "r", stdin);
    int T, n;
    cin >> T;
    
    while (T--) {
        cin >> n;
        int a[n];

        for (int t=0;t<n;++t)
            cin >> a[t];

        sort(a, a+n);
        int ct = 0, ins = INT_MIN;
        for (int t=0;t<n;t++) {
            if ((a[t] == a[t+1] - 1) || (a[t] == a[t-1]+1) || (a[t]-1 == ins)) {
                continue;
            }
            ins = a[t] + 1;
            ++ct;
        }
        cout << ct << '\n';
    }
}
