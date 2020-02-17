#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
 
using namespace std;
typedef unsigned long long int ulli;
 
 
int main() {
 
    const unsigned long long MOD7 = 1000000000+7;
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {
 
 
        int x, y, a, b;
        cin >> x;
        cin >> y;
        cin >> a;
        cin >> b;
 
        int d = y - x;
        int s = a + b;
        if (d % s == 0)
            cout << d / s << endl;
        else
            cout << -1 << endl;
 
    }
}