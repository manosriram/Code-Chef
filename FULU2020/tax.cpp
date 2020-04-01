#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int aa = s[0] - '0',
        bb = s[1] - '0',
        cc = s[2] - '0';

    if (aa + bb > cc) cout << "Inclusive";
    else cout << "Exclusive";
}
