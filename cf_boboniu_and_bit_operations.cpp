#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int N, M;
    cin >> N >> M;

    vector<int> a_vec(N, 0);
    vector<int> b_vec(M, 0);

    for(int n = 0; n < N; n++) {
        cin >> a_vec[n];
    }

    for(int m = 0; m < M; m++) {
        cin >> b_vec[m];
    }

    const int TWO_TO_9 = int(pow(2, 9));
    int min_a = numeric_limits<int>::max();
    for(int k = 0; k < TWO_TO_9; k++) {

        int n_js = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int c_i = a_vec[i] & b_vec[j];


                if((c_i | k) == k) {
                    n_js++;
                    break;
                }

            }
        }

        if(n_js == N) {
            if(min_a > k)
                min_a = k;
        }
    }

    cout << min_a << endl;
}