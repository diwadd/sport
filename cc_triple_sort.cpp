#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

void make_shift(int i1, int i2, int i3, vector<int> &p){

    printf("input: %d %d %d\n", i1, i2 , i3);

    int v1 = p[i1];
    int v2 = p[i2];
    int v3 = p[i3];

    p[i2] = v1;
    p[i3] = v2;
    p[i1] = v3;
}


class Moves {
    public:
        Moves() {i = 0; j = 0; k = 0;};
        Moves(int ii, int jj, int kk): i(ii), j(jj), k(kk) {};
        int i;
        int j;
        int k;
};


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    int T;
    scanf("%d", &T);    
    for(int i = 0; i < T; i++) {

        int N, K;
        scanf("%d %d", &N, &K);

        vector<int> v(N+1, 0);
        for(int j = 1; j <= N; j++) {
            int p;
            scanf("%d", &p);
            v[j] = p;
        }

        int p = 0;
        vector<vector<pair<int,int>>> vector_of_transpositions;
        vector<vector<int>> vector_of_cycles;
        for(int j = 1; j <= v.size()-1; j++) {

            vector<pair<int, int> > transposition;
            vector<int> cycle = {j};
            while(v[j] != j){
                transposition.push_back(make_pair(j, v[j]));
                p = p + 1;
                cycle.push_back(v[j]);
                swap(v[j], v[v[j]]);
            }

            if(cycle.size() > 1) {
                vector_of_cycles.push_back(cycle);
            }

        }

        if(p % 2 == 1) {
            printf("-1\n");
            continue;
        }

        vector<Moves> vector_of_moves;
        int rem_1 = 0;
        int rem_2 = 0;
        for(int j = 0; j < vector_of_cycles.size(); j++) {

            if(vector_of_cycles[j].size() % 2 == 1) {

                for(int k = 1; k < vector_of_cycles[j].size(); k = k + 2) {
                    Moves m;
                    m.i = vector_of_cycles[j][0];
                    m.j = vector_of_cycles[j][k];
                    m.k = vector_of_cycles[j][k+1];
                    
                    vector_of_moves.push_back(m);
                }

            } else {

                for(int k = 1; k < vector_of_cycles[j].size() - 1; k = k + 2) {

                    Moves m;
                    m.i = vector_of_cycles[j][0];
                    m.j = vector_of_cycles[j][k];
                    m.k = vector_of_cycles[j][k+1];
                    
                    vector_of_moves.push_back(m);
                }

                if(rem_1 == 0 && rem_2 == 0){
                    rem_1 = vector_of_cycles[j][0];
                    rem_2 = vector_of_cycles[j][vector_of_cycles[j].size() - 1];
                    continue;
                } else {
                    
                    int rem_3 = vector_of_cycles[j][0];
                    int rem_4 = vector_of_cycles[j][vector_of_cycles[j].size() - 1];

                    Moves m1(rem_1, rem_2, rem_3);
                    Moves m2(rem_1, rem_4, rem_3);

                    vector_of_moves.push_back(m1);
                    vector_of_moves.push_back(m2);
                    rem_1 = 0;
                    rem_2 = 0;
                }
            }
        }

        int M = vector_of_moves.size();
        printf("%d\n", M);

        for(int j = 0; j < vector_of_moves.size(); j++) {
            printf("%d %d %d\n", vector_of_moves[j].i, vector_of_moves[j].j, vector_of_moves[j].k);
        }

    }
}