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
int tree[1600];

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

void fillOVLP() {
    int y1 = 1;
    while (y1 <= 398) {
        int dayIn = findFF(2, y1);
        int dayNx = getPenSunday(2, y1);

        if ((dayNx >= dayIn) && (dayNx <= (dayIn + 10)))
            a[y1] = y1;

        ++y1;
    }
}

void buildTree(int st, int ed, int tN) {
    if(st == ed) {
        tree[tN] = (a[st] != 0) ? 1 : 0;
        return;
    }
    int mid = (st + ed) / 2;
    buildTree(st, mid, 2 * tN);
    buildTree(mid+1, ed, (2 * tN) + 1);
    tree[tN] = tree[2 * tN] + tree[(2 * tN) + 1];
}

int Query(int st, int ed, int qSt, int qEd, int tN) {
    int mid = (st + ed) / 2;

    if (qSt <= st && qEd >= ed)
        return tree[tN];

    else if ((qSt >= st && qEd <= ed) || (qEd >= st && qSt <= ed))
        return (Query(st, mid, qSt, qEd, 2 * tN) + Query(mid+1, ed, qSt, qEd, (2 * tN) + 1));

    else
        return 0;
}

int main() {
    clock_t tStart = clock();
    int T, a1, a2, b1, b2;
    FASTER;

    fillOVLP();
    buildTree(1, 400, 1);

    cin >> T;
    while(T--) {
        cin >> a1 >> b1 >> a2 >> b2;
        if (a1 > 2)
            ++b1;
        if (a2 > 2)
            --b2;

        int diff = b2 - b1;
        // cout << Query(tree, 1, 400, 1, 200, 1) << endl;
        if (diff > 400) {
            int div = (diff / 400), md = (diff % 400);
            if (b2 % 100 == 0)
                ++md;
            int res = (101 * div) + Query(1, 400, 1, md, 1);
            cout << res << '\n';
        } else {
            if (b1 > 400 && b2 > 400)
                cout << Query(1, 400, (b1 % 400), (b2 % 400), 1) << '\n';
            else if (a1 > 400)
                cout << Query(1, 400, (b1 % 400), b2, 1) << '\n';
            else if (b1 > 400)
                cout << Query(1, 400, b1, (b2 % 400), 1) << '\n';
            else
                cout << Query(1, 400, b1, b2, 1) << '\n';
        }
    }
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
