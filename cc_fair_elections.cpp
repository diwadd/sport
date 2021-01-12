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
 
        int N, M;
        cin >> N >> M;

        vector<int> a_vec(N, 0);
        vector<int> b_vec(M, 0);

        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        for(int i = 0; i < M; i++) {
            cin >> b_vec[i];
        }

        sort(a_vec.begin(), a_vec.end());
        sort(b_vec.begin(), b_vec.end());

        int john_votes = accumulate(a_vec.begin(), a_vec.end(), 0);
        int jack_votes = accumulate(b_vec.begin(), b_vec.end(), 0);

        if(john_votes > jack_votes) {
            cout << "0\n";
            continue;
        }

        int a_index = 0;
        int b_index = M-1;
        int res = 0;

        while(true) {
            if(a_vec[a_index] < b_vec[b_index]) {
                john_votes = john_votes - a_vec[a_index] + b_vec[b_index];
                jack_votes = jack_votes + a_vec[a_index] - b_vec[b_index];

                int box = a_vec[a_index];
                a_vec[a_index] = b_vec[b_index];
                b_vec[b_index] = box;

                b_index--;
                a_index++;

                res++;

                if(b_index < 0 || a_index >= N)
                    break;

                if(john_votes > jack_votes)
                    break;

            } else {
                break;
            }
        }
    
        if(john_votes > jack_votes) {
            cout << res << "\n";
        } else {
            cout << "-1\n";
        }
    }
}