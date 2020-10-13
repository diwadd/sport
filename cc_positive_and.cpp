#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

template<typename T> void print_vector(vector<T> &vec) {

    int n = vec.size();
    for(int i = 1; i < n; i++) {
        if(i == n - 1)
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }
    cout << "\n";
}

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        print_vector(mat[i]);
    }
}


bool check_if_permutation_is_beautiful(vector<int> &vec){

    bool res = true;
    for(int i = 1; i < vec.size() - 1; i++) {
        if( (vec[i] & vec[i+1]) <= 0 ) {
            res = false;
            break;
        }
    }
    return res;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        // if(N % 1000 == 0){
        //     cout << "N: " << N << endl;
        // }

        if(N == 1) {
            cout << "1\n";
            continue;
        }

        // Is power of 2???
        if((N & (N - 1)) == 0) {
            cout << "-1\n";
            continue;
        }

        vector<int> p_vec(N+1, 0);

        int max_power_of_2 = (int)(log2(N));
        int index = 0;
        for(int i = 0; i <= max_power_of_2; i++) {

            int start = int(pow(2.0, i));
            int stop = min( int(pow(2.0, i+1)), N);
            if(stop == N) {
                stop++;
            }
            // cout << "start: " << start << " stop: " << stop << "\n";
            for(int j = start; j < stop; j++) {
                // cout << "j: " << j << "\n";
                p_vec[j] = j;
            }

            int box = p_vec[start];
            p_vec[start] = p_vec[start + 1];
            p_vec[start + 1] = box;

        }

        p_vec[1] = 2;
        p_vec[2] = 3;
        p_vec[3] = 1;

        print_vector(p_vec);
        
        // if(check_if_permutation_is_beautiful(p_vec) == false)
        //     cout << "Is beautiful: " << check_if_permutation_is_beautiful(p_vec) << endl;

    }


}