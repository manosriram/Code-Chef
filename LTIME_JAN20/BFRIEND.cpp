#include <iostream>
#include <limits.h>
#define ld long long int
using namespace std;

int main() {
   ld T, n, a, b, c;
  cin >> T;
 while (T--) {
    cin >> n >> a >> b >> c;
    ld min_ = INT_MAX, temp;
    for (ld t=0;t<n;++t) {
       cin >> temp;
       if (temp < min_) min_ = temp;
    }

    ld time;
    time = abs(b - min_);
    time += c;
    time += abs(min_ - a);

    cout << time << '\n';
 } 
}

