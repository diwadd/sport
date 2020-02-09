#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long int ulli;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {

        int n;
        cin >> n;

        int sum = 0;
        int moves = 0;
        for(int j = 0; j < n; j++) {
            int aj;
            cin >> aj;

            if (aj == 0) {
                moves++;
                sum = sum + 1;
            } else {
                sum = sum + aj;
            }
        }

        if (sum != 0) {
            cout << moves << endl;
        } else {
            cout << moves + 1 << endl;
        }

    }
}