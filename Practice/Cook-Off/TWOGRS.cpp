#include <iostream>
using namespace std;

int main() {
    int T, n;
    int a, b, c;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        n = a + b + c;

        int ar[n], in = -1;

        int rem = (a * 1) + (b * 2) + (c * 3);
        while (a--) ar[++in] = 1;
        while (b--) ar[++in] = 2;
        while (c--) ar[++in] = 3;

        int sum = 0, prev = 0;

        int t;
        for (t=0;t<n;t++) {
            if (ar[t] + sum > rem) {
                sum -= prev;
                rem += prev;
                sum += ar[t];
                rem -= ar[t];
            } else {
                sum += ar[t];
                rem -= ar[t];
            }
            prev = ar[t];
            if (sum == rem)
                break;
        }
        if (t == n)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}
