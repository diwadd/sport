#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        lli N, X;
        cin >> N >> X;
 
        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        sort(a_vec.rbegin(), a_vec.rend());
        // print_vector(a_vec);

        lli n_teams = 0;
        lli n_programmers = 0;
        lli n_minimal_skill = numeric_limits<lli>::max();
        for(int i = 0; i < N; i++) {
            if(a_vec[i] >= X){
                n_teams++;
            } else {

                n_programmers++;
                if(a_vec[i] <= n_minimal_skill)
                    n_minimal_skill = a_vec[i];

                if(n_programmers*n_minimal_skill >= X){
                    n_teams++;
                    n_programmers = 0;
                    n_minimal_skill = numeric_limits<lli>::max();
                }
            }
        }
        cout << n_teams << "\n";
    }
}