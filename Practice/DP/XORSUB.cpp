#include <iostream>
using namespace std;

int main() {
    int T, n, k, tm;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int max_ = k;
        for (int t=0;t<n;++t) {
            cin >> tm;
            max_ = max(max_, (tm ^ k));
        }
        cout << max_ << endl;
    }
}
