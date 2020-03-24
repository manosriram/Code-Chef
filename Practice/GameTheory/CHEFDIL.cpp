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

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    ll T, sm;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        sm = 0;
        for (int t=0;t<s.length();++t) 
            sm += (s[t] == '1');

        if (sm & 1) cout << "WIN";
        else cout << "LOSE";

        cout << endl;
    }


#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
