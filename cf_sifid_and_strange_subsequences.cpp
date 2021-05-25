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
 
        int N;
        cin >> N;

        vector<int> vec(N, 0);
        int min_ele = numeric_limits<int>::max();
        int n_negative = 0;
        for(int i = 0; i < N; i++) {
            cin >> vec[i];
            if(vec[i] > 0)
                min_ele = min(min_ele, vec[i]);
            if(vec[i] <= 0)
                n_negative++;
        }

        sort(vec.begin(), vec.end());

        bool is_ok;
        if(min_ele != numeric_limits<int>::max()) {
            is_ok = true;
            for(int i = 1; i < N; i++) {
                if(vec[i] <= 0)
                    if( abs(vec[i] - vec[i-1]) < min_ele )
                        is_ok = false;
            }

        } else {
            is_ok = false;
        }

        if(is_ok)
            cout << n_negative + 1 << "\n";
        else
            cout << n_negative << "\n";

    }
}