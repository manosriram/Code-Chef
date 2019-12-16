#include <iostream>
#include <chrono>
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

bitset<bN> XOR(bitset<bN> btA, bitset<bN> btB, int n) {
    bitset<bN> temp;
    for (int t=0;t<n;++t)
        temp[t] = btA[t] ^ btB[t];

    return temp;
}

bitset<bN> AND(bitset<bN> btA, bitset<bN> btB, int n) {
    bitset<bN> temp;
    for (int t=0;t<n;++t)
        temp[t] = btA[t] & btB[t];

    return temp;
}


bool check(bitset<bN> b, int n) {
    for (int t=0;t<n;t++) {
        if (b[t] == 1) return true;
    }
    return false;
}

void printBT(bitset<bN> b, int n) {

    for (int t=0;t<n;t++) cout << b[t];

    cout << endl;
    return;
}

int main() {
    freopen("in.txt", "r", stdin);
    FASTER;
    string a, b;
    int T;
    cin >> T;
    while (T--) {
        bool rec= false;
        int iter = 0;
        cin >> a >> b;
        int aN = a.end() - a.begin(), bN_ = b.end() - b.begin();
        int max_ = max(aN, bN_) - 1;

        bitset<bN> btA((string(a)));
        bitset<bN> btB((string(b)));
        bitset<bN> u, v;

        while (check(btB, ++max_)) {
            printBT(btB, max_);
            ++iter;
            u = XOR(btA, btB, max_);
            v = AND(btA, btB, max_);
            btA = u;
            btB = (v << 1);
        }
        cout << iter << '\n';
    }

}
