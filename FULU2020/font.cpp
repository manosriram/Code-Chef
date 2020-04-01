// amtresmhhxew montycerofx windoshelvetica elunorgreetings
#include <iostream>
using namespace std;

int main() {
    string ss[] = {"amtresmhhxew", "montycerofx", "windoshelvetica", "elunorgreetings"};
    int n;
    cin >> n;
    int ct = 0;
    while (ct != 3) {
        int in = (n % 4);
        cout << ss[in] << " ";
        n /= 2;
        ++ct;
    }
}
