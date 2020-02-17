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
    FASTER;
    long long int T, n, sum, temp;
    cin >> T;
    vector<long long int> a, b;
    while (T--) {
        sum = 0;
        a.clear();
        b.clear();
        long long int n;
        cin >> n;

        for (long long int t=0;t<n;++t) {
            cin >> temp;
            a.pb(temp);
        }
        sort(a.begin(), a.end());

        for (long long int t=0;t<n;++t) {
            cin >> temp;
            b.pb(temp);
        }
        sort(b.begin(), b.end());

        for (long long int t=0;t<n;++t) {
            if (b[t] > a[t])
                sum += a[t];
            else
                sum += b[t];
        }
        cout << sum << endl;
    }
}
