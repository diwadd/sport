#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;


template<typename T> void prulli_vector(vector<T> &vec) {

    for(ulli i = 0; i < vec.size(); i++) {
        if(i != vec.size()-1)
            cout << vec[i] << " ";
        else
            cout << vec[i];
    }
    cout << "\n";
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ulli T;
    cin >> T;

    for(ulli t = 0; t < T; t++) {

        ulli N;
        cin >> N;
        // N = t + 1;

        ulli total_sum = N*(N+1) / 2;
        if(total_sum % 2 != 0) {
            cout << "0\n";
            continue;
        }

        ulli b = total_sum / 2;

        ulli m_low = floor( 0.5*(sqrt(1.0 + 8.0*b) - 1.0) );
        ulli m_high = ceil( 0.5*(sqrt(1.0 + 8.0*b) - 1.0) );

        ulli res = 0;
        if(m_low == m_high) {
            ulli lower_half = m_low - 1;
            res = res + ((lower_half + 1) * lower_half) / 2;
            ulli upper_half = N - m_low - 1;
            res = res + ((upper_half + 1) * upper_half) / 2;
        }

        res = res + (N - m_low);

        cout << res << "\n"; 
    }
}