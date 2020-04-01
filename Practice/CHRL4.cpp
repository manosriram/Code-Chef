#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int t=0;t<n;++t) cin >> a[t];

    int cur = a[n-1], mm = a[0] * a[n-1];
    for (int t=n-2;t>=0;--t) {
        if (cur - a[t] >= 1 && cur - a[t] <= k) continue;

        cur = a[t+1], mm *= cur;

        mm %= 1000000007;
    }
    cout << (mm % 1000000007);
}

