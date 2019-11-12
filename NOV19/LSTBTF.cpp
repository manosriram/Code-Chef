#include <iostream>
#include <math.h>
using namespace std;

bool isOK(vector<int> v) {
    int s = 0;
    for (auto t : v) {
        s += t * t;
    }
    long double sr = sqrt(s); 
  
    return ((sr - floor(sr)) == 0); 
}

void addOne(vector<int> v, int n) {



    if (v[n-1] != 9 && v[n-1] != 0)
        ++v[n-1];
    else {
        for (int t=n-1;t>=0;--t) {
            if (v[t] == 9)
                v[t] = 1;
            else {
                ++v[t];
                break;
            }
        }
    }
    return;
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        freopen("out.txt", "w", stdout);
        v.clear();

        cin >> n;
        vector<int> v(n, 1);

                     


    }
}
