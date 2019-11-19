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
    vi v;
    int n, k, T, temp, res;
    bool done;
    cin >> T;
    while(T--) {
        v.clear();
        cin >> n >> k;
        for (int t=1;t<=n;t++) {
            cin >> temp;
            v.push_back(temp);
        }
        for (int t=0;t<n;t++) {
            temp = v[t];  
            if (temp >= k) {
                res += temp - k;
            } else {
                if (temp + res < k) {
                    cout << "NO " << t+1 << '\n';
                    done = true;
                    break;
                } else {
                res -= k - temp;
                }
            }
        }
        if (!done)
            cout << "YES" << '\n';
        res = 0;
        done= false;
    }
}
