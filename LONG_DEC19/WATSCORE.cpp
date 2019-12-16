#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    int tO, sc, tt;
    cin >> T;
    map<int, int> mp;
    
    while (T--) {
        mp.clear();
        tt = 0;
        cin >> n;

        while (n--) {
            cin >> tO >> sc;
            if (tO > 0 && tO < 9)
                mp[tO] = max(mp[tO], sc);
        }
        for (auto it = mp.begin();it!=mp.end();it++)
            tt += it->second;

        cout << tt << '\n';
    }
}
