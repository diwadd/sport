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


        int n;
        cin >> n;

        vector<int> a(n, 0);

        for(int j = 0; j < n; j++) {
            int aj;
            cin >> aj;
            a[j] = aj;
        }

        bool is_inter = false;
        int el = -1;
        int er = -1;
        for(int j = 1; j < n; j++) {
            int d = abs(a[j-1] - a[j]);
            if (d >= 2) {
                is_inter = true;
                el = j-1;
                er = j;
                break;
            }
        }

        if (is_inter == true) {
            cout << "YES" << endl;
            cout << el + 1 << " " << er + 1 << endl;
        } else {
            cout << "NO" << endl;
        }




    }


}