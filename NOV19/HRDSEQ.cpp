#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;

int main() {
    int T, n, x;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> T;
    vector<int> v;
    unordered_map<int, pair<int, int> > mp;
    while (T--) {
        x = 0;
        mp.clear();
        v.clear();
        cin >> n;
        v.push_back(0);
        int sz = 1;
        for (int t=0;t<n;t++) {
            ++mp[x].second;

            if (!mp[x].first) {
                mp[x].first = t+1;
                v.push_back(0);
            } else {
                if (mp[x].second >= 1) {
                    v.push_back(sz - mp[x].first);
                } else {
                    v.push_back(0);   
                }
                mp[x].first = t+1;
            }
            ++sz;
            x = v[sz - 1];
        }
        cout << mp[v[v.size() - 2]].second << '\n';
    }
} 
