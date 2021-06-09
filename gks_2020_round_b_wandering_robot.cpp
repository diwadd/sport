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
    for(int i = 0; i < n; i++) {
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

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int MAX_GRID_SIZE = 100 + 7;

    vector<double> log_power_2(MAX_GRID_SIZE, 0.0);
    vector<double> log_factorial(MAX_GRID_SIZE, 0.0);

    for(int i = 1; i < MAX_GRID_SIZE; i++) {
        log_power_2[i] = double(i);
        log_factorial[i] = log_factorial[i-1] + log2(i);
    }


    auto get_p = [&](int n, int k) {
        if(n < 0 || k < 0 || k > n)
            return 0.0;
        return pow(2, log_factorial[n] - log_factorial[k] - log_factorial[n-k] - log_power_2[n]);
    };

    // print_vector(log_power_2);
    // print_vector(log_factorial);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int W, H, L, U, R, D;
        cin >> W >> H >> L >> U >> R >> D;

        vector<pair<int, int>> valid_points;

        // // Valid points above
        // for(int i = 1; i < max(W, H); i++) {
        //     int x = L - i;
        //     int y = D + i;

        //     if(x < 1 || y > H)
        //         break;
            
        //     auto p = make_pair(L - i, D + i);
        //     valid_points.push_back(p);
        // }

        // Valid points below
        for(int i = 1; i < max(W, H); i++) {
            int x = R + i;
            int y = U - i;

            if(x > W || y < 1)
                break;
            
            auto p = make_pair(R + i, U - i);
            valid_points.push_back(p);
        }

        double res = 0.0;

        for(int i = 0; i < valid_points.size(); i++) {

            auto point = valid_points[i];
            int x = point.first;
            int y = point.second;

            double p = get_p(x + y - 2, y);
            cout << "x: " << x << " y: " << y << " probability: " << p << "\n";

            res += p;
        }


        for(auto p : valid_points) {
            cout << p.first << " " << p.second << "\n";
        }


        cout << "res: " << res << endl;
    }


}