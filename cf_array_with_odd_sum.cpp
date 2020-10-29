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
 
        vector<int> a(n,0);
        for(int j = 0; j < n; j++){
            int aj;
            cin >> aj;
            a[j] = aj;
        }

        int n_odd = 0;
        int n_even = 0;
        for(int j = 0; j < n; j++){
            if(a[j] % 2 == 0)
                n_even++;
            else
                n_odd++;
        }


        if(n % 2 == 0 && n_even == 0 && n_odd != 0){
            cout << "NO" << endl;
        } else if (n % 2 != 0 && n_even == 0 && n_odd != 0){
            cout << "YES" << endl;
        } else if ( (n % 2 == 0 || n % 2 != 0) && n_even != 0 && n_odd == 0){
            cout << "NO" << endl;
        } else if ( (n % 2 == 0 || n % 2 != 0) && n_even != 0 && n_odd != 0){
            cout << "YES" << endl;
        }

    }
 
 
}