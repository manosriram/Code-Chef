// g++ -std=c++17 cpp.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl "\n"
#define pb push_back
#define rep(t, n) for (int t=0;t<(n);++t)
const ll NN = 1e5+5;
using namespace std;
int setBitNumber(int n) 
{ 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n = n + 1; 
    return (n >> 1); 
} 
int main() {
    IOS;
    int n;
    cin >> n;
    n -= (n & -n);
    n >>= 1;
    cout << n;
}
