#include <iostream>
#include "unordered_map"
#include <vector>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;

inline double round( double val )
{
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

int main() {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    string s;
    int T, n;
    cin >> T;
    int vo, con;
    double prodA, prodB;
    unordered_map<char, pair<double, double> > mpA, mpB;

    while (T--) {
        mpA.clear();
        mpB.clear();
        cin >> n;
        for (int z=0;z<n;z++) {
            vo = 0;
            con = 0;
            cin >> s;
            int le = s.end() - s.begin();

            for (int t=0;t<le;t++) {
                if (s[t] == 'a' || s[t] == 'e' || s[t] == 'i' || s[t] == 'o' || s[t] == 'u') ++vo;
                else ++con;
            }
            bool done[26];
            memset(done, false, 26);
            if (vo >= con) {
                for (int t=0;t<le;t++) {
                    if (!done[s[t] - 'a']) {
                        mpA[s[t]].first = mpA[s[t]].first + 1.0;
                        done[s[t] - 'a'] = true;
                    }
                    mpA[s[t]].second = mpA[s[t]].second + 1.0;
                }
            } else {
                for (int t=0;t<le;t++) {
                    if (!done[s[t] - 'a']) {
                        mpB[s[t]].first = mpB[s[t]].first + 1.0;
                        done[s[t] - 'a'] = true;
                    }
                    mpB[s[t]].second = mpB[s[t]].second + 1.0;
                }
            }
        }
        double n1 = 1.0, n2 = 1.0, n3 = 1.0, n4 = 1.0;

        for (auto t = mpA.begin(); t!=mpA.end(); t++) {
            n1 = n1 * t->second.first;
            n2 = n2 * pow(t->second.second, 2.0);
        }

        for (auto t = mpB.begin(); t!=mpB.end(); t++) {
            n3 = n3 * t->second.first;
            n4 = n4 * pow(t->second.second, 2.0);
        }
        double ra1 = round((n1 * n4) * 1000.0) / 1000.0;
        double ra2 = round((n2 * n3) * 1000.0) / 1000.0;

        double rat = (double) ra1/ra2;

        if (rat > 1e7)
            printf("Infinity\n");
        else
            printf("%.7f\n", rat);
    }
}
