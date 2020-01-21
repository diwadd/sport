#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;
typedef unsigned long long int ulli;

ulli pow_ulli(ulli x, ulli n){

    ulli xn = 1;
    for(ulli i = 0; i < n; i++)
        xn = xn*x;

    return xn;
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {

        ulli n;
        cin >> n;

        ulli a;
        cin >> a;

        // In the below line we explicitly make that
        // the maximal sum must be composed out of 4 numbers:
        // the first two are equal to 10^n-1 and the last to are equal to 1.
        // The ones can be of cource reduced :-)
        ulli s = a + (pow_ulli(10, n) - 1) + (pow_ulli(10, n) - 1) + 1 + 1;
        cout << s << endl << flush;

        ulli b;
        cin >> b;

        ulli c = pow_ulli(10, n) - b;
        cout << c << endl << flush;

        ulli d;
        cin >> d;

        ulli e = s - a - b - c - d;
        cout << e << endl << flush;

        // cout << "Provided number: " << endl;
        // cout << "a: " << a << endl;
        // cout << "b: " << b << endl;
        // cout << "c: " << c << endl;
        // cout << "d: " << d << endl;
        // cout << "e: " << e << endl;
        // cout << "Provided s: " << s << endl;
        // cout << "Actual s: " << a + b + c + d + e << endl;

        int r;
        cin >> r;
        if (r == -1)
            break;
    }
}