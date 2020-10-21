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
            cout << vec[i];
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
 
        int N;
        cin >> N;

        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        set<int> s(a_vec.begin(), a_vec.end());
        if(s.size() == 1) {
            cout << "NO\n";
            continue;
        }

        vector<pair<int, vector<int>>> graph;
        int INIT_CAPA = 100;
        for(int i = 0; i < N; i++) {
            pair<int, vector<int>> p = {a_vec[i], vector<int>()};
            graph.push_back(p);
            graph.back().second.reserve(INIT_CAPA);
        }

        for(int i = 0; i < N; i++) {

            if(graph[i].second.size() != 0) {
                continue;
            }

            for(int j = 0; j < N; j++) {
                if(graph[j].first == a_vec[i])
                    continue;                

                graph[j].second.push_back(i);
                break;

            }
        }

        cout << "YES\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < graph[i].second.size(); j++) {
                cout << i + 1 << " " << graph[i].second[j] + 1 << "\n";
            }
        }

    }


}