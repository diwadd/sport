#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


struct pair_hash {
    ulli operator () (const pair<ulli, ulli> &p) const {
        auto h1 = std::hash<ulli>{}(p.first);
        auto h2 = std::hash<ulli>{}(p.second);

        return h1 ^ h2;  
    }
};

ulli get_minimal_number_of_boxes(ulli height_one,
                                 ulli height_two,
                                 ulli n,
                                 ulli &N,
                                 ulli &K,
                                 vector<ulli> &h_vec,
                                 unordered_map<pair<ulli, ulli>, ulli, pair_hash> &lookup) {

    if (height_one >= K and height_two >= K) {
        return n;
    }
    if (n == N) {
        return numeric_limits<ulli>::max();
    }

    if (lookup.find(pair<int, int>(height_one, height_two)) == lookup.end()) {
        ulli r1 = 0;
        ulli r2 = 0;

        if(height_one < K) {
            r1 = get_minimal_number_of_boxes(height_one + h_vec[n], height_two, n + 1, N, K, h_vec, lookup);
        } else {
            r1 = numeric_limits<ulli>::max();
        }

        if(height_two < K) {
            r2 = get_minimal_number_of_boxes(height_one, height_two + h_vec[n], n + 1, N, K, h_vec, lookup);
        } else {
            r2 = numeric_limits<ulli>::max();
        }
        lookup[pair<ulli, ulli>(height_one, height_two)] = min(r1, r2);
    }

    return lookup[pair<ulli, ulli>(height_one, height_two)];
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        ulli N, K;
        cin >> N >> K;

        vector<ulli> h_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> h_vec[i];
        }

        sort(h_vec.rbegin(), h_vec.rend());


        unordered_map<pair<ulli, ulli>, ulli, pair_hash> lookup;
        lookup.reserve(N);
        ulli res = get_minimal_number_of_boxes(0, 0, 0, N, K, h_vec, lookup);
        
        if (res == numeric_limits<ulli>::max()) {
            cout << "-1\n";
        } else {
            cout << res << "\n";
        }
    }


}