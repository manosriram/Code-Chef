#include <iostream>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        freopen("out.txt", "w", stdout);
        cin >> n;
        int n1 = n;
        bool hZ = true;
        while (n) {
            if (n % 10 == 0) {
                hZ = false;
                break;
            }

            n /= 10;
        }
        
        cout << hZ;

    }
}
