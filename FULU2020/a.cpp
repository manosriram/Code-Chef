// g++ -std=c++17 a.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl "\n"
#define pb push_back
#define rep(t, n) for (int t=0;t<(n);++t)
const ll NN = 1e5+5;
using namespace std;

int main() {
    // freopen("out", "w", stdout);
    IOS;
    int n, ct = 0;
    cin >> n;
    while (n) {
        ct += (n & 1);
        n >>= 1;
    }
    cout << ct;
}

