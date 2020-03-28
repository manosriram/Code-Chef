// g++ -std=c++17 DIGJUMP.cpp -o a.out && ./a.out < in
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
#endif
    string s;
    cin >> s;
    int n = s.length();
    stack<int> *ss = new stack<int>[10];
    for (int t=0;t<n;++t)
        ss[s[t] - '0'].push(t);

    int in = n - 1, jmps = 0;
    int nwIn = in;
    while (in > 0) {
        cout << in << " ";
        ++jmps;
        if (!ss[s[in] - '0'].empty()) 
            ss[s[in] - '0'].pop();

        if (!ss[s[in] - '0'].empty()) {
            in = ss[s[in] - '0'].top();
        }
        else in--;
        for (int t=nwIn;t>=in;--t) if(!ss[s[t] - '0'].empty()) ss[s[t] - '0'].pop();

        nwIn = in;
    }
    cout << jmps << endl;

#ifndef ONLINE_JUDGE
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif

}
