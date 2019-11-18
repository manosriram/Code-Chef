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
typedef unordered_map<int, int> ump;

int getMin(vector<int> v, int st, int ed) {
    int min_ = INT_MAX;

    for (int t=st;t<=ed;t++)
        if (v[t] < min_)
            min_ = v[t];
    
    
    return min_;
}

int main() {
    int T, n, temp;
    int ct;
    cin >> T;
    vector<int> v;
    ct = 1;
    while (T--) {
        v.clear();
        cin >> n;
        int st = 0, ed;
        for (int t=1;t<=n;t++) {
            cin >> temp;
            v.emplace_back(temp);
        }
        for (int t=1;t<=n;t++) {
            if (t % 7 == 0)
                ++st;
            if (v[t] < getMin(v, st, t-1))
               ++ct; 
        }
        cout << ct << '\n';
    }
}
