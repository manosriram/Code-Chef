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

void flip(int *a, int in) {
}

int main() {
    clock_t tStart = clock();
    //freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, k, n;
    int ct;
    cin >> T;
    int in;
    while (T--) {
        ct = 0;
        cin >> n >> k;
        char a[n];
        in = n-1;
        for (int t=0;t<n;++t) cin >> a[t];

        for (int l=0;l<k;++l) {
            if (a[in] == 'H'){
                for (int t=0;t<in;++t) {
                    if (a[t] == 'H') a[t] = 'T';
                    else a[t] = 'H';
                }
            }
            --in;
        }

        for (int t=0;t<n-k;++t) if (a[t] == 'H') ++ct;

        cout << ct << '\n';
    }

    // cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
