#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include "unordered_map"
#define F first
#define S second
#define ll long long int
#define pb push_back
#define debug cout << "hi" << '\n';
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
using namespace std;

void buildTree(string s, int st, int ed, int tN, char *tree) {
    if (st == ed) {
        tree[tN] = s[st];
        return;
    }
    int mid = (st + ed) / 2;

    buildTree(s, st, mid, 2 * tN, tree);
    buildTree(s, mid+1, ed, (2 * tN) + 1, tree);
    tree[tN] = (tree[2 * tN] == tree[(2 * tN) + 1]) ? tree[tN] : '$';
}

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("in", "r", stdin);
#endif

    string s;
    cin >> s;
    char *tree = new char[32];
    buildTree(s, 0, s.length() - 1, 1, tree);

    for (int t=1;t<=15;++t) {
        cout << "hi: ";
        cout << tree[t] << " ";
    }

#ifndef ONLINE_JUDGE
    cout << endl;
    cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
#endif
}
