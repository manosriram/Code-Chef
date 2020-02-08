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
    int n, T;
    cin >> T;
    int w1, w2, w3, s;
    int hits;

    while(T--) {
        hits = 0;
        cin >> s >> w1 >> w2 >> w3;

        if (w1+w2+w3 <= s)
            hits = 1;
        else if ((w1 + w2 <= s) || (w2 + w3 <= s))
            hits = 2;
        else
            hits = 3;

        cout << hits << '\n';
    }
}
