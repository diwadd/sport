#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int MAX_DIM = 1000;
    vector<vector<ulli>> mat(MAX_DIM+1, vector<ulli>(MAX_DIM+1, 0));

    vector<ulli> v(2*MAX_DIM, 1);
    for(ulli i = 1; i < MAX_DIM; i++) {
        v[i] = v[i-1] + (i+1);
    }

    for(ulli i = 1; i <= MAX_DIM; i++) {
        ulli val = v[i-1];
        ulli delta = i;
        for(ulli k = 1; k <= MAX_DIM; k++) {


            mat[i][k] = val;
            val = val + delta;
            delta++;
        }
    }

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ulli sum = 0;

        if(x1 == x2 && y1 == y2) {
            sum += mat[x1][y1];
        } else if(y1 == y2) {

            for(int i = x1; i <= x2; i++) {
                sum += mat[i][y2];
            }

        } else if(x1 == x2) {

            for(int i = y1; i <= y2; i++) {
                sum += mat[x1][i];
            }

        } else {

            for(int i = x1; i <= x2; i++) {
                sum += mat[i][y1];
            }

            for(int i = y1+1; i <= y2; i++) {
                sum += mat[x2][i];
            }

        }

        cout << sum << "\n";
    }
}