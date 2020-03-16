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

void showGR(int n) {
    for (int t=1;t<=n;++t) {
        for (int j=1;j<=n;++j) {
            cout << gr[t][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int gr[n+1][n+1];
        int a[n+1];

        for (int t=1;t<=n;++t) {
            for (int j=1;j<=n;++j) {
                gr[t][j] = 1;
            }
        }
        for (int t=1;t<=n;++t) gr[t][t] = 0;

        while (k--) {
        for (int t=0;t<n;++t) cin >> a[t];
            for (int t=0;t<n-1;++t) {
                for (int j=t+1;j<n;++j) {
                    gr[a[j]][a[t]] = 0;
                }
            }
        }

        bool inz;
        bool inn[n+1];
        int over = 0;
        for (int t=1;t<=n;++t) {
            inz = true;
            for (int j=1;j<=n;++j) {
                if (gr[t][j]) {
                    inz = false;
                    break;
                }
            }
            inn[t] = inz;
            if (inz) ++over;
        }

        cout << over << '\n';
        for (int t=1;t<=n;++t) {
            if (inn[t])
                cout << 0 << " ";
            else {
                for (int j=1;j<=n;++j) {
                    if (gr[t][j]) {
                        cout << j << " ";
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
}
