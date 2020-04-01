#include <iostream>
#include <math.h>
#include <cstring>
#define ll long long
using namespace std;
int SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 

    int ct = 0;
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
           ++ct;

    return ct;
} 
int main() {
    int n;
    cin >> n;
    cout << SieveOfEratosthenes(n);
}

