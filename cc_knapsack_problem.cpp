#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

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

ulli knapsack(int n, int capacity, vector<int> &w_vec, vector<int> &c_vec, vector<vector<ulli>> &dp) {

    if (n == -1 or capacity == 0) {
        return 0;
    } else if (dp[n][capacity] != -1) {
        return dp[n][capacity];
    } else if (w_vec[n] > capacity) {
        if(dp[n][capacity] != -1)
            return dp[n-1][capacity];
        else
            return knapsack(n - 1, capacity, w_vec, c_vec, dp);
    } else {
        ulli t1 = knapsack(n - 1, capacity, w_vec, c_vec, dp);
        ulli t2 = c_vec[n] + knapsack(n - 1, capacity - w_vec[n], w_vec, c_vec, dp);
        dp[n][capacity] = max(t1, t2);
        return dp[n][capacity];
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
 
    vector<int> w_vec(N, 0);
    vector<int> c_vec(N, 0);

    int M = 0;
    for(int i = 0; i < N; i++) {
        int w, c;
        cin >> w >> c;

        w_vec[i] = w;
        c_vec[i] = c;
        M += w;
    }

    vector<ulli> res(M, 0);
    vector<vector<ulli>> dp(N, vector<ulli>(M+1, -1));
    for(int m = 1; m <= M; m++) {
        // cout << "m: " << m << endl;
        res[m-1] = knapsack(N-1, m, w_vec, c_vec, dp);

    }    

    print_vector(res);

}