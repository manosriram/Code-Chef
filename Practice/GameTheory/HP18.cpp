#include <iostream>
using namespace std;

int main() {
    int T, n, a, b, tm;
    int bob, alice, bb;
    bool A, B;
    cin >> T;
    while (T--) {
        bob = alice = bb = 0;
        A = B = false;
        cin >> n >> a >> b;
        while (n--) {
            cin >> tm;
            if (tm % a == 0) ++bob;
            else if (tm % b == 0) ++alice;
            else if (tm % a && tm % b) ++bb;
        }
        if (bb) ++bob;

        if (!bb)
            puts(bob > alice ? "BOB" : "ALICE");
        else
            puts(bob >= alice ? "BOB" : "ALICE");
    }
}
