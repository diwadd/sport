#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
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
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;

        int a_max = numeric_limits<int>::min();
        int a_max_index = 0;
        vector<int> a_vec(N, 0);
        vector<int> marks(N, 0);
        for(int i = 0; i < N; i++){
            cin >> a_vec[i];
            if(a_max < a_vec[i]){
                a_max = a_vec[i];
                a_max_index = i;
            }
        }

        int checked_as = 1;
        marks[a_max_index] = 1;;
        vector<int> b_vec;
        b_vec.push_back(a_max);

        int c_gcd = a_max;
        while(checked_as != N) {

            int max_gcd = numeric_limits<int>::min();
            int a_max = numeric_limits<int>::min();
            int max_index = -1;
            for(int i = 0; i < N; i++) {
                if(marks[i] == 1)
                    continue;
            
                int d = __gcd(c_gcd, a_vec[i]);
                if(max_gcd < d) {
                    max_gcd = d;
                    a_max = a_vec[i];
                    max_index = i;
                }
                if(d == max_gcd && a_vec[i] > a_max) {
                    a_max = a_vec[i];
                    max_index = i;
                }
            }

            // cout << "max_gcd: " << max_gcd << " a_max: " << a_max << endl;
            c_gcd = max_gcd;
            b_vec.push_back(a_max);
            marks[max_index] = 1;
            checked_as++;

        }

        print_vector(b_vec);

    }
}