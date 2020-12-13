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
 
        int N, K;
        cin >> N >> K;

        string s = "";

        string a_part(K, 'a');
        string b_part(K, 'b');
        string c_part(K, 'c');        

        string res = "";
        int abc = 1;
        while(res.size() < N) {
            if(abc == 1) {
                res = res + a_part; 
                abc = 2;
            } else if(abc == 2) {
                res = res + b_part;
                abc = 3;
            } else if(abc == 3) {
                res = res + c_part;
                abc = 1;
            }
        }

        string res_f(N, 'x');

        for(int i = 0; i < N; i++) {
            res_f[i] = res[i];
        }

        cout << res_f << "\n";
    }
}