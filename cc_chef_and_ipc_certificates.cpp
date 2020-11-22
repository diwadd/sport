#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ulli N, M, K;
    cin >> N >> M >> K;

    ulli res = 0;
    for(ulli i = 0; i < N; i++) {

        vector<ulli> t_vec(K, 0);
        for(ulli k = 0; k < K; k++) {
            cin >> t_vec[k];
        }
        ulli q;
        cin >> q;

        ulli total_time = accumulate(t_vec.begin(), t_vec.end(), 0);

        if(total_time >= M && q <= 10){
            res++;
        }
    }
    cout << res << "\n";

}