#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include "unordered_map"
#define F first
#define S second
#define ll long long int
#define pb push_back
#define debug cout << "hi" << '\n';
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int a[n];
    
    for (int t=0;t<n;++t) cin >> a[t];

    int odd, even, sum;
    for (int t1=1;t1<=100;++t1) {
        cout << t1 << " : ";
        odd = 0, even = 0, sum = 0;
        for (int t=0;t<n;++t) {
            cout << (t1 ^ a[t]) << " ";
            
            if (__builtin_popcount(t1 ^ a[t]) & 1)
                ++odd;
            else ++even;

            sum += (t1 ^ a[t]);
        }
        cout << " | " << even << " " << odd << " " << sum << endl;
    }    
}
