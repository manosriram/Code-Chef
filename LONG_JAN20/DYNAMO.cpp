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
    long int T, n, a, b, c, d, e, res, sm, s;
    cin >> T;
    while (T--) {
        cin >> n >> a;
        s = pow(10, n)/2;
        sm = s-a;
        cout << s << endl;
        cin >> b;
        sm -= b;
        c = sm/2;
        sm -=c;
        cout << c << endl;
        cin >> d;
        sm -= d;
        e = sm;
        cout << e << endl;
        cin >> res;
        if (res == -1)
            break;
        cout << endl;
    }
}
