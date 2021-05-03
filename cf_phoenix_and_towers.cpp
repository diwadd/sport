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

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N, M, X;
        cin >> N >> M >> X;

        vector<int> h_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> h_vec[i];
        }


        vector<pair<int,int>> tower;
        for(int i = 0; i < M; i++) {
            pair<int,int> p = make_pair(0, i);
            tower.push_back(p);
        }

        auto comp = [](pair<int,int> p1, pair<int,int> p2) { return p1.first > p2.first; }; 
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

        for(int i = 0; i < M; i++) {
            pair<int,int> p = make_pair(0, i);
            pq.push(p);
        }

        vector<int> tower_locations(N, 0);

        for(int i = 0; i < N; i++) {
            pair<int,int> p = pq.top();

            // cout << "p: " << p.first << " " << p.second << endl;

            p.first += h_vec[i];
            tower_locations[i] = p.second+1;
            pq.pop();
            pq.push(p);
        }

        cout << "YES\n";
        print_vector(tower_locations);
    }


}