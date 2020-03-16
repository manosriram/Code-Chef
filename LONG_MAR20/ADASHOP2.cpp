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
const int N = 8;
int board[9][9];
bool visited[9][9] = {{false}};
int visits;

void reset() {
    for (int t=1;t<=N;++t) {
        for (int j=1;j<=N;++j) {
            visited[t][j] = false;
        }
    }
    visits = 0;
}

bool isSafe(int rr, int cc) {
    return (rr > 0 && rr < 9 && cc > 0 && cc < 9);
}

void printBoard() {
    for (int t=1;t<=N;++t) {
        for (int j=1;j<=N;++j) {
            cout << board[t][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << endl;
    return;
}

bool allVis() {
    for (int t=1;t<=8;++t) {
        for (int j=1;j<=8;++j) {
            if (board[t][j] == 1 && !visited[t][j]) return false;
        }
    }
    return true;
}

vector<pair<int, int>> moves;
bool Solve(int rr, int cc) {
    if (rr < 1 || rr > 8 || cc < 1 || cc > 8) return false;

    if (allVis()) return true;
    visited[rr][cc] = true;


    moves.pb(make_pair(rr, cc));
    board[rr][cc] = 2;
    
    if (!visited[rr+1][cc+1]) {
        if (Solve(rr+1, cc+1))
            moves.pb(make_pair(rr, cc));
    }
    if (!visited[rr+1][cc-1]) {
        if (Solve(rr+1, cc-1))
            moves.pb(make_pair(rr, cc));
    }
    if (!visited[rr-1][cc+1]) {
        if (Solve(rr-1, cc+1))
            moves.pb(make_pair(rr, cc));
    }
    if (!visited[rr-1][cc-1]) {
        if (Solve(rr-1, cc-1))
            moves.pb(make_pair(rr, cc));
    }
    return true;
}


void fillBoard() {
    for (int t=1;t<=8;++t) {
        if (t % 2 == 0) {
            for (int j=1;j<=8;++j) {
                if (j % 2 == 0)
                    board[t][j] = 1;
                else
                    board[t][j] = 0;
            }
        } else {
            for (int j=1;j<=8;++j) {
                if (j % 2 == 0)
                    board[t][j] = 0;
                else
                    board[t][j] = 1;
            }
        }
    }
}

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int T;
    cin >> T;

    int r, c;
    while (T--) {
        cin >> r >> c;
        
        moves.clear();
        fillBoard();
        reset();

        Solve(r, c);

        cout << moves.size() << '\n';
        for (auto it = moves.begin();it != moves.end(); ++it)
            cout << it->first << " " << it->second << '\n';
    }
}
