#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N;
    cin >> N;

    lli MOD_7 = 1000000000 + 7;

    vector<lli> a_vec(N, 0);
    lli res = 0;
    for(int i = 0; i < N; i++) {
        cin >> a_vec[i];        
        res = ((res % MOD_7) + (a_vec[i] % MOD_7) + MOD_7) % MOD_7;
    }

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        lli x;
        cin >> x;
        res = ((res % MOD_7) + (res % MOD_7) + MOD_7) % MOD_7;
        cout << (res % MOD_7) << "\n";
    }


}