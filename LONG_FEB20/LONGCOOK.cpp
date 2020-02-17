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
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 4 == 0 && y % 100 != 0) return true;

    return false;
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

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ld T;
    int m1, m2, y1, y2, mnts;
    int dayIn, dayNx;
    int mnth = 2;
    cin >> T;
    vector<int> a, mn;

    while (T--) {
        mnts = 0;
        cin >> m1 >> y1 >> m2 >> y2;
        int prev1 = 9, prev2 = 15;
        while (true) {
            dayIn = findFF(m1, y1);
            dayNx = getPenSunday(m1, y1);

            if ((dayNx >= dayIn) && (dayNx <= (dayIn + 10))) {
                if (isLeap(y1))
                   cout << m1 << " " << y1 << " " << dayIn << " " << dayNx << " " << " LEAP" << endl;
                else
                   cout << m1 << " " << y1 << " " << dayIn << " " << dayNx << " " << endl;

                a.pb(y1);
                ++mnts;
                mn.pb(mnts);
            }
            if (m1 == 12) {
                m1 = 1;
                ++y1;
            } else ++m1;
            if (y1 == y2) break;
        }
    }
}
