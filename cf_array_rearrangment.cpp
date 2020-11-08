#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int n, x;
        cin >> n >> x;

        vector<int> a_vec(n, 0);
        vector<int> b_vec(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> a_vec[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> b_vec[i];
        }


        sort(a_vec.begin(), a_vec.end());
        sort(b_vec.rbegin(), b_vec.rend());

        bool is_ok = true;
        for(int i = 0; i < n; i++) {

            if(a_vec[i] + b_vec[i] > x){
                is_ok = false;
                break;
            }

        }

        if (is_ok == true)
            cout << "YES\n";
        else
            cout << "NO\n";

    }


}