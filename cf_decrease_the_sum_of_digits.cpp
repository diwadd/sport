#include <bits/stdc++.h> 
 
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;

ulli sum_digits(ulli N) {

    ulli sum = 0;
    while(N > 0) {
        sum = sum + (N % 10);
        N = N / 10;
    }
    return sum;
}
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {

        ulli N, S;
        cin >> N >> S;

        if(sum_digits(N) <= S) {
            cout << "0\n";
            continue;
        }

        ulli req = 0;
        ulli multi = 1;
        while(true) {

            ulli d = (N / multi) % 10;
            N = N + ((10 - d) % 10) * multi;
            req = req + ((10 - d) % 10) * multi;
            multi = multi * 10;

            if(sum_digits(N) <= S){
                cout << req << "\n";
                break;
            }

        }
    }
}