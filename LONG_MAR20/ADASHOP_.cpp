#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 8;
bool visited[N][N] = { { false } };
int board[9][9];

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

bool isSafeMove(int r1, int c1, int r2, int c2) {
    return ((r1 + c1 == r2 + c2) || (r1 - c1 == r2 - c2));
}

int vis = 0;
bool Solve(int rr, int cc) {
    if (!isSafe(rr, cc)) return false;

    for (int t=1;t<=N;++t) {
        for (int j=1;j<=N;++j) {
            if (isSafeMove(rr, cc, t, j)) {
                visited[t][j] = true;
                board[t][j] = 2;
                Solve(t, j);
                // visited[t][j] = false;
            }
        }
    }
    return false;
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    int rr, cc;
    cin >> T;
    fillBoard();
    while (T--) {
        cin >> rr >> cc;

        Solve(rr, cc);
        printBoard();
    }
}

