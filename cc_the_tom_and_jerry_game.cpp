#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;
typedef long double long_double;

ulli number_of_two_divisors(ulli TS) {

    ulli n_2 = 0;
    while(TS % 2 == 0){
        n_2++;
        TS = TS / 2;
    }

    return n_2;
}


ulli fast_solution(ulli TS) {

    if(TS % 2 != 0)
        return TS / 2;

    if( (TS != 0) && !(TS & (TS - 1)) ){
        return 0;
    }

    ulli n_2 = number_of_two_divisors(TS) + 1;
    ulli p2 = pow(2, long_double(n_2));

    return floor( long_double((TS - p2) / (p2)) ) + 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        ulli TS;
        cin >> TS;

        ulli res = fast_solution(TS);
        cout << res << "\n";


    }
}