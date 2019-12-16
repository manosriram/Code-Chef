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
    int T;
    cin >> T;
    string a, b;
    while (T--) {
        int le = 0;
        bool isZ = false;
        cin >> a >> b;
        int aN = a.length(), bN = b.length();
        if (aN <= bN) {
            int diff = bN - aN;
            while (diff--) a = '0' + a;
        } else {
            int diff = aN - bN;
            while (diff--) b = '0' + b;
        }

        for (int t=0;t<b.length();t++) {
            if (b[t] == '1') {
                isZ = true;
                break;
            }
        }
        if (isZ) le = 1;
        int n = min(a.length(), b.length());

        int maxFar = INT_MIN;
        for (int t=n-1;t>=0;--t) {
            int ct = le+1;
            if (a[t] == '1' && b[t] == '1') {
                int in = t - 1;
                while ((a[in] != b[in]) && in >= 0) {
                    ++ct;
                    --in;
                }

                if (ct > maxFar) {
                    maxFar = ct;
                }
            }
        }
        if (maxFar == INT_MIN)
            maxFar = le;
        cout << maxFar << '\n';
    }
}
