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

        vector<vector<int>> a_mat(N, vector<int>(M, 0));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> a_mat[i][j];
            }
        }

        vector<map<int,int>> diagonals;
        for(int d = 0; d < M; d++) {

            map<int,int> diag;
            for(int i = 0; i < N; i++) {
                if(i >= N || i+d >= M)
                    continue;
            
                diag[a_mat[i][i+d]]++;
            }
            diagonals.push_back(diag);
        }

        int Q;
        cin >> Q;

        for(int i = 0; i < Q; i++) {

            int x, y, v;
            cin >> x >> y >> v;

            x--;
            y--;

            int d = abs(x-y);

            map<int,int> *p = &diagonals[d];

            if(p->find(v) == p->end()) {

                int o = a_mat[x][y];
                (*p)[o]--;
                if((*p)[o] == 0){
                    auto it = p->find(o);
                    p->erase(it);
                }

                (*p)[v]++;
                a_mat[x][y] = v;
            } else {
                int o = a_mat[x][y];
                if(o == v){
                    (*p)[v]++;
                } else {
                    (*p)[o]--;

                    if((*p)[o] == 0){
                        auto it = p->find(o);
                        p->erase(it);
                    }

                    (*p)[v]++;
                }
                a_mat[x][y] = v;
            }

            bool is_ok = true;
            for(int j = 0; j < diagonals.size(); j++) {
                if(diagonals[j].size() != 1) {
                    is_ok = false;
                    break;
                }
            }

            if(is_ok == true) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }

    }

}