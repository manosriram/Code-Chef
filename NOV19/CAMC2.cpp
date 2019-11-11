#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#define SPEED cin.sync_with_stdio(false);cin.tie(NULL);
using namespace std;

long long int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    SPEED;
    vector<long long int> v;
    long long int T, n, m;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        long long int temp;

        for (long long int t=0;t<n;t++) {
            cin >> temp;
            v.push_back(temp);
        }
        long long int in, diff = INT_MAX;
        for (long long int t=0;t<n/2;t++) {
            in = t;
            for (long long int j=t+1;j<n;j++) {
                if (j != in + m) {
                    if (abs(v[t] - v[j]) < diff)
                        diff = abs(v[t] - v[j]);
                }
            }
        }
        cout << diff << '\n';
    }
}
