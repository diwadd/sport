#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

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

        vector<int> a(2*n, 0);
        for(int j = 0; j < 2*n; j++) {
            int aj;
            cin >> aj;
            a[j] = aj;
        }

        sort(a.begin(), a.end());
        int low = a[n-1];
        int high = a[n];

        cout << high - low << endl;

    }
}