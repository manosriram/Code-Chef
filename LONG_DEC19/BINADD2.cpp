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
typedef pair<int, int> pr;
typedef unordered_map<int, int> ump;
int ct;
map<char, int> mp;

inline string AND(string a, string b) {
    mp.clear();
    string res;
    int n = a.end() - a.begin();
    for (int t=0;t<n;t++) {
        char bit = (((a[t] - '0') & (b[t] - '0')) + '0');
        mp[bit] = 1;
        res.push_back(bit);
    }
    return res;
}

inline string XOR(string a, string b) {
    string res;
    int n = a.end() - a.begin();
    for (int t=0;t<n;t++)
        res.push_back(((a[t] - '0') ^ (b[t] - '0')) + '0');

    return res;
}

int main() {
    FASTER;
    int T;
    cin >> T;

    while (T--) {
        mp.clear();
        string a, b;
        cin >> a >> b;
        int aN = a.end() - a.begin(), bN = b.end() - b.begin();

        for (int t=0;t<bN;t++) {
            mp[b[t]] = 1;
        }

        if (aN >= bN) {
            int diff = aN - bN;
            while (diff--) {
                b = '0' + b;
            }
        } else {
            int diff = bN - aN;
            while (diff--) {
                a = '0' + a;
            }
        }
        string u, v;
        int iter = 0;

        cout << a << " " << b << endl << endl;
        while (mp['1'] == 1) {
            ++iter;
            u = XOR(a, b);
            v = AND(a, b);
            a = '0' + u;
            b = v + '0';
            cout << a << " " << b << endl << endl;
        }
    }
}
