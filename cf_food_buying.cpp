#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
 
using namespace std;
typedef unsigned long long int ulli;
 
int main() {
 
    const int n_bits = 32;
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++){
 
        int n;
        cin >> n;
 
        int res = 0;
        while(true) {

            if (n >= 10) {
                int e = n / 10;
                int r = n % 10;
                res = res + e*10;
                n = e + r;
            } else {
                res = res + n;
                break;
            }

        }

        cout << res << endl;

    }
 
 
}