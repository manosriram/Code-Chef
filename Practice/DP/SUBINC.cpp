#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll T, n;
    ll sum;
    cin >> T;
    while (T--) {
        sum = 1;
        cin >> n;
        ll a[n], dp[n];
        dp[0] = 1;
        for (int t=0;t<n;++t) cin >> a[t];
        for (int t=1;t<n;++t) {
            if (a[t] >= a[t-1]) dp[t] = dp[t-1] + 1;
            else dp[t] = 1;

            sum += dp[t];
        }
        cout << sum << endl;
    }
}

