#include <vector>
#include <iostream>
using namespace std;

int sti = -1;

bool chk(int *a, int n, int k) {
    for (int t=1;t<n;++t) 
        if (a[t] <= a[t-1]) return false;

    return true;
}

int perm(int *a, int in, int n, int k, vector<int> st) {
    if (in == n) {
        sti = -1;
        for (int t=0;t<n;++t) cout << a[t] << " ";

        cout << endl;
        return chk(a, n, k);
    }

    if (a[in] == 0) a[in] = st[++sti];

    return perm(a, in+1, n, k, st);
}

int main() {
    freopen("in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        vector<int> st;
        int n, k;
        cin >> n >> k;
        int a[n+1];

        for (int t=0;t<n;++t) {
            cin >> a[t];
            if (a[t] != 0) st.push_back(a[t]);
        }

    }
}

