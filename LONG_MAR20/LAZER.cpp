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

struct Point {
    ll x, y;

    Point(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
};

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
ll orientation(Point p, Point q, Point r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;
  
    return (val > 0)? 1: 2;
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    ll o1 = orientation(p1, q1, p2); 
    ll o2 = orientation(p1, q1, q2); 
    ll o3 = orientation(p2, q2, p1); 
    ll o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
} 

int main() {
    FASTER;
    ll T, n, q;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        ll a[n+2];
        for (ll t=1;t<=n;++t) cin >> a[t];

        ll x1, x2, y;
        while (q--) {
            ll does = 0;
            cin >> x1 >> x2 >> y;
            for (ll t=1;t<n;++t) {

                Point px(t, a[t]);
                Point py(t+1, a[t+1]);
                Point pxx(x1, y);
                Point pyy(x2, y);

                if ((px.x == pyy.x && px.y == pyy.y) || (py.x == pxx.x && py.y == pxx.y)) continue;
                if (doIntersect(px, py, pxx, pyy))
                    ++does;
            }
            cout << does << '\n';
        }
    }
}
