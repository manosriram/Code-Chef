#include <iostream>
#include <set>
#include "unordered_map"
using namespace std;
int odd, even;

int countBits(int n) {
    int cntr = 0;
    while (n) {
        if (n & 1)
            ++cntr;

        n >>= 1;
    }
    return cntr;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T, q, x;
    cin >> T;
    set<int> s;
    unordered_map<int, int> mp;
    while (T--) {
        even = 0, odd = 0;
        cin >> q;
        s.clear();
        mp.clear();
        int in = -1;
        while (q--) {
            cin >> x;
            for (auto e: mp)
                mp[++in] = e.second^x;

            mp[++in] = x;
            int bits;
            for (int f=in;f>=in/2;--f) {
                bits = countBits(mp[f]);
                if (bits & 1) ++odd;
                else ++even;
            }

            cout << even << " " << odd << '\n';
        }
    }
}

