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
#include <time.h>
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ld long long int
typedef vector<int> vi;
typedef pair<int,int> pi;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, a[405], sum = 0;
int dp[405];

bool isLeap(int y) {
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0) return true;
            return false;
        } else return true;
    } else return false;
}

int findDay(int d, int m, int y) {
    if (m == 1) {
        m = 13;
        --y;
    } if (m == 2) {
        m = 14;
        --y;
    }

    int N = d + (2 * m) + (3 * (m + 1)/5) + y + (y/4) - (y/100) + (y/400) + 1;

    return (N % 7);
}

int getPenSunday(int m, int y) {
    bool L = isLeap(y);
    int dy;

    if (L && m == 2)
        dy = days[m-1] + 1;
    else
        dy = days[m-1];

    int in = findDay(dy, m, y);
    if (in == 0)
        return (dy - 7);

    return (dy - (in + 7));
}

int findFF(int m, int y) {
    int dy = findDay(1, m, y);
    if (dy == 0)
        dy = 7;

    if (dy == 5)
        return 1;
    if (dy < 5)
        return (dy + (4 - dy));

    return (8 - (dy - 5));

}

void fillOVLP() {
    dp[0] = 0;
    int y1 = 1;
    while (y1 <= 400) {
        int dayIn = findFF(2, y1);
        int dayNx = getPenSunday(2, y1);

        if ((dayNx >= dayIn) && (dayNx <= (dayIn + 10))) {
            a[y1] = 1;
            dp[y1] = dp[y1 - 1] + 1;
        } else
            dp[y1] = dp[y1-1];

        // cout << y1 << " " << dp[y1] << endl;
        ++y1;
    }
}

int main() {
    // clock_t tStart = clock();
    // freopen("in.txt", "r", stdin);
    int T, a1, a2, b1, b2, diff, res;
    FASTER;

    fillOVLP();
    cin >> T;
    while(T--) {
        cin >> a1 >> b1 >> a2 >> b2;
        res = 0;
        if (a1 > 2) ++b1;
        if (a2 < 2) --b2;

        if (b1 >= 400 && b2 >= 400) {
            res = ((101 * (b2 / 400)) + dp[b2 % 400]) - ((101 * (b1 / 400)) + dp[b1 % 400]);
            if (b1 % 400 != 0)
                res += dp[b1 % 400] - dp[(b1 - 1) % 400];
        } else if (b1 >= 400) {
            res = ((101 * (b2 / 400)) + dp[b2]) - ((101 * (b1 / 400)) + dp[b1 % 400]);
            if (b1 % 400 != 0)
                res += dp[b1 % 400] - dp[(b1 - 1) % 400];
        } else if (b2 >= 400) {
            res = ((101 * (b2 / 400)) + dp[b2 % 400]) - ((101 * (b1 / 400)) + dp[b1]);
            res += dp[b1] - dp[b1 - 1];
        } else {
            res = ((101 * (b2 / 400)) + dp[b2]) - ((101 * (b1 / 400)) + dp[b1]);
            res += dp[b1] - dp[b1 - 1];
        }
        cout << res << endl;
    }
}
