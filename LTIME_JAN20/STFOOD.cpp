#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int T, n, now, max_;
    int s, v, p;
    cin >> T;
    while (T--) {
        cin >> n;
        max_ = 0;
        for (int t=0;t<n;++t) {
            cin >> s >> p >> v;
            ++s;
            if (p % s != 0)
                now = p/s;
            else
               now = (p * v)/s;

            if (now > max_)
                max_ = now;
        }
        if (max_ < 0) max_ = 0;

        cout << max_ << '\n';
    }
}

