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
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> pi;
ll max_ = INT_MIN, total = 0;
ll takenR[4], takenC[4];
int N = 4;
int costs[4] = {100, 75, 50, 25};

bool isSafe(ll mt[4][4], int r, int c) {
    if (!takenR[r] && !takenC[c])
        return true;

    return false;
}

void Solve(ll mt[4][4], int col, int rowFill[]) {
    if (col >= N) {
        int tempR[4];
        for (int t=0;t<4;++t)
            tempR[t] = rowFill[t];

        int prf = 0, pIn = 0;
        sort(tempR, tempR + 4, greater<int>());

        for (int t=0;t<4;++t) {
            if (tempR[t] == 0)
                prf -= 100;
            else {
                // cout << rowFill[t] << " " << costs[pIn] << endl;
                prf += costs[pIn] * tempR[t];
                pIn++;
            }
        }
        if (prf > max_)
            max_ = prf;
        return;
    }

    for (int t=0;t<4;++t) {
        if (isSafe(mt, t, col)) {
            takenR[t] = true;
            takenC[col] = true;
            rowFill[col] = mt[t][col];

            Solve(mt, col + 1, rowFill);

            rowFill[col] = 0;
            takenR[t] = false;
            takenC[col] = false;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    FASTER;
    ll T, n, t;
    char m;
    cin >> T;
    while (T--) {
        max_ = INT_MIN;
        cin >> n;
        memset(takenR, false, sizeof(takenR));
        memset(takenC, false, sizeof(takenC));
        ll mt[4][4];
        int rowFill[4];
        memset(rowFill, 0, sizeof(rowFill));
        for (int t=0;t<4;++t)
            for (int j=0;j<4;++j)
                mt[t][j] = 0;

        while (n--) {
            cin >> m >> t;

            mt[m - 'A'][(t/3) - 1]++;
        }

        Solve(mt, 0, rowFill);
        total += max_;
        cout << max_ << '\n';
    }
    cout << total << '\n';
}
