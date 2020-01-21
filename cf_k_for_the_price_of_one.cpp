#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){

        int n, p, k;
        cin >> n >> p >> k;

        vector<int> a(n, 0);
        for(int j = 0; j < n; j++){
            int aj;
            cin >> aj;
            a[j] = aj;
        }

        sort(a.begin(), a.end());

        int res = 0;
        int last = -1;
        bool too_little = false;
        for(int j = k - 1; j < n; j = j + k) {
            if( a[j] <= p){
                res = res + k;
                p = p - a[j];
                last = j + 1;
            } else {
                last = j - k + 1;
                break;
            }
        }

        if (last == -1)
            last = 0;

        int b = min(last + k, n);

        for(int j = last; j < b; j++) {
            if (a[j] <= p) {
                res = res + 1;
                p = p - a[j];
            } else {
                break;
            }
        }


        cout << res << endl;

    }


}