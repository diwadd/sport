#include <bits/stdc++.h> 

using namespace std;
typedef long long int ulli;


void print_vector(vector<int> &vec) {

    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

void print_map(map<int, int> &m) {

    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " <-> " << it->second << "\n";
    }
}


int main() {

    const unsigned long long MOD7 = 1000000000+7;
    const unsigned long long MAX_NUMBERS = 200000 + 7;

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T;
    // cin >> T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++) {

        int K;
        scanf("%d", &K);

        int dim = 8;
        vector<vector<char>> cb(dim, vector<char>(dim, 'X'));

        int n_moves = 0;
        cb[0][0] = 'O';
        n_moves++;

        for(int i = 0; i < dim; i++) {

            if(n_moves == K)
                break;

            for(int j = 0; j < dim; j++) {

                if(n_moves == K)
                    break;

                if(cb[i][j] == 'O')
                    continue;

                if(cb[i][j] == 'X'){
                    cb[i][j] = '.';
                    n_moves++;
                }


            }
        }


        for(int i = 0; i < dim; i++) {
            for(int j = 0; j < dim; j++) {

                if(j != 7)
                    printf("%c", cb[i][j]);
                else
                    printf("%c\n", cb[i][j]);

            }
        }


    }
}
