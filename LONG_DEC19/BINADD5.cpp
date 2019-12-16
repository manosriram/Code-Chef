#include <iostream>
#include <string.h>
using namespace std;
bool zero = false;

pair<string, string> XAND(string a, string b, int n) {
    string X, A;
    int ct = 0;
    for (int t=0;t<n;t++) {
        if (a[t] == '1' && b[t] == '1')
            A.push_back('1');
        else {
            ++ct;
            A.push_back('0');
        }

        if (a[t] == b[t])
            X.push_back('0');
        else
            X.push_back('1');
    }
    if (ct == n)
        zero = true;
    else
        zero = false;

    return make_pair(X, A);
}

int main() {
    int T;
    string a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int an = a.length(), bn = b.length();
        int max_ = max(an, bn);
        
        if (max_ == an) {
            int ln = max_  - bn;
            while (ln--) b = '0' + b;
        } else {
            int ln = max_ - an;
            while (ln--) a = '0' + a;
        }

        while (

    }
}
