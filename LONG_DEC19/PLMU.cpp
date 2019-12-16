#include <iostream>
#include <map>
#include <iterator>
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
typedef pair<int, int> pi;


int main() {
    // freopen("in.txt", "r", stdin);
    FASTER;
    int T, n;
    cin >> T;
    
    while (T--) {
        cin >> n;
        int a[n];

        for (int t=0;t<n;t++)
            cin >> a[t];

        int z = 0, tw = 0;

        for (int t=0;t<n;t++) {
            if (a[t] == 2)
                ++tw;
            if (a[t] == 0)
                ++z;
        }
        tw = (tw * (tw - 1))/2;
        z = (z * (z - 1))/2;

        cout << tw + z << '\n';
    }
}
