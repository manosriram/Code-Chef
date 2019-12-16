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
    string a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int aN = a.end() - a.begin(), bN = b.end() - b.begin();
        int up = aN - 1, dw = bN - 1;
        
        int ct = 0;
        for (int t=0;t<bN;t++)
            if (b[t] == '1')
                ct = 1;

        while (up >= 0 && dw >= 0) {
            if (a[up] == '1' && b[dw] == '1') {
                --up;
                ++ct;
            } else {
                --up;
                --dw;
            }
        }
        cout << ct << '\n';
    }
}
