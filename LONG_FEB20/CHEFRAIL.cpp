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
typedef vector< pair<int, int> > vpi;

double dist(pair<int, int> p, pair<int, int> q) {
    double res = sqrt(pow(q.first - p.first, 2) +
                pow(q.second - p.second, 2) * 1.0);

    cout << res << endl;
    return res;
}

template <typename T>
bool ApproximatelyEqual(const T dX, const T dY)
{
    return std::abs(dX - dY) <= std::max(std::abs(dX), std::abs(dY))
    * std::numeric_limits<T>::epsilon();
}

void printPTS(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    cout << "(" << a.first << ", " << a.second << "), " << 
         "(" << b.first << ", " << b.second << "), " <<
         c.first << ", " << c.second << "), " << endl;

    return;
}

int main() {
    freopen("in.txt", "r", stdin);
    clock_t tStart = clock();
    int T, n, m, temp, right;
    vpi pts;
    vector<double> ds;
    cin >> T;
    while (T--) {
        cin >> n >> m;

        right = 0;
        pts.clear();

        for (int t=0;t<n;++t) {
            cin >> temp;
            pts.pb(make_pair(temp, 0));
        }

        for (int t=0;t<m;++t) {
            cin >> temp;
            pts.pb(make_pair(0, temp));
        }

        for (int t=0;t<n+m;++t) {
            for (int j=0;j<n+m;++j) {
                if (t != j) {
                    for (int k=0;k<n+m;++k) {
                        if (k != j && k != t) {
                            // printPTS(pts[t], pts[j], pts[k]);
                            ds.pb(dist(pts[t], pts[j]));
                            ds.pb(dist(pts[t], pts[k]));
                            ds.pb(dist(pts[j], pts[k]));


                            sort(ds.begin(), ds.end());
                            //cout << ds[0] * ds[0] + ds[1] * ds[1] - ds[2] * ds[2] << endl;
                                if (ApproximatelyEqual(pow(ds[0], 2) + pow(ds[1], 2) - pow(ds[2], 2), 0.0)) {
                                    ++right;
                            }

                        }
                    }
                }
            }
        }
        cout << right << endl;
    }

    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
