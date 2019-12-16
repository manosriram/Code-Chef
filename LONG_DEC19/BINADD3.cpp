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
#include <bitset>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define ld long long int
#define bN 100000
typedef vector<int> vi;
typedef pair<int, int> pr;
typedef map<int, int> mp;
typedef unordered_map<int, int> ump;

bitset<bN> XOR(bitset<bN> a, bitset<bN> b, int le) {
    bitset<bN> temp;
    for (int t=0;t<le;t++)
       temp[t] = a[t] ^ b[t];

    return temp;
}

bitset<bN> AND(bitset<bN> a, bitset<bN> b, int le) {
    bitset<bN> temp;
    for (int t=0;t<le;t++)
        temp[t] = a[t] & b[t];

    return temp;
}

bool ANY(bitset<bN> b, int le) {
    for (int t=0;t<=le;t++) {
        if (b.test(t))
            return true;
    }
    return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    FASTER;
    string a, b;
    int T;
    cin >> T;
    while (T--) {
        int iter = 0;
        cin >> a >> b;
        int max_ = max((a.end() - a.begin()), b.end() - b.begin());
        bitset<bN> btA((string(a)));
        bitset<bN> btB((string(b)));
        bitset<bN> u, v;
        
        int n = log2((a.end() - a.begin()) + (b.end() - b.begin()));
        while (n--) {
            ++iter;
            //u = btA ^ btB;
            u = XOR(btA, btB, max_);
            //v = btA & btB;
            v = AND(btA, btB, max_);
            btA = u;
            btB = (v << 1);
        }
        cout << iter << '\n';
    }

}
