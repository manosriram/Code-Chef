#include <iostream>
#include <vector>
#include <map>
using namespace std;

void addEdge(vector<int> grph[], int src, int dest) {
    grph[src].push_back(dest);
    return;
}

void moveVtx(int vtx, map<int, bool> &sourceSet, map<int, bool> &destinationSet) {
    sourceSet[vtx] = false;
    destinationSet[vtx] = true;
    return;
}

map<int, bool> cycle;
map<int, bool> whiteSet, blackSet, graySet;
bool hasCycle(vector<int> grph[], int vtx) {
    cout << vtx << " ";
    moveVtx(vtx, whiteSet, graySet);
    for (auto edg: grph[vtx]) {
        if (blackSet[edg]) continue;
        if (graySet[edg]) return true;
        if (hasCycle(grph, edg)) return false;
    }
    moveVtx(vtx, graySet, blackSet); 
    return false;
}

void printG(vector<int> g[], int n) {
    for (int t=0;t<n;++t) {
        for (auto e: g[t])
            cout << e << " ";

        cout << endl;
    }
    return;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, nd;
    cin >> n;
    vector<int> *grph = new vector<int>[n+3];
    for (int t=0;t<n;++t) {
        cin >> nd;
        int dt = (1 + nd) + t;
        addEdge(grph, t, (dt % n));
        whiteSet[t] = true;
    }
    int magic = 0;
    for (int t=0;t<n;++t) {
        if (hasCycle(grph, t)) ++magic;

        cout << endl;
    }

    cout << magic;
}

