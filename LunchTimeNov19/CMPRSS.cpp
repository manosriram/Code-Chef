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
    //freopen("in.txt", "r", stdin);
    int T, n;
    cin >> T;
    string st;

    while (T--) {
        st = "";
        cin >> n;
        int a[n], t;

        for (int t=0;t<n;t++) {
            cin >> a[t];
        }

        int ct = 0, prev, lp = 0;
        while (ct < n) {
            prev = ct;

            for (t=lp;t<n-1;t++) {
                if (a[t] == a[t+1] - 1)
                    continue;

                break;
            }
            ct = t;
            lp = ct+1;

            if (a[ct] <= a[prev]+1) {
                if (a[ct] != a[prev])
                    st += std::to_string(a[prev]) + "," + std::to_string(a[ct]) + ",";
                else
                    st += std::to_string(a[prev]) + ",";
            }
            else {
                st += std::to_string(a[prev]) + "..." + std::to_string(a[ct]) + ",";
            }

            ++ct;
        }
        int nl = st.end() - st.begin();
        st = st.substr(0, nl - 1);
        cout << st << '\n';
    }
}
