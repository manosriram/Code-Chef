#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long int n, T;
    cin >> T;
    while (T--) {
        cin >> n;
        char s[100000];
        vector<long int> v;

        for (int t=0;t<n;++t) {
            cin >> s;
            long int z;
            z = stoull(s, 0, 2);
            v.push_back(z);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        long int zz = v[0];

        for (int t=1;t<v.size();++t) {
            zz ^= v[t];
        }        
        
       int set = 0;
      while (zz) {
         if (zz & 1)
            ++set;

        zz >>= 1;
      } 
     cout << set << '\n';
    }
}
