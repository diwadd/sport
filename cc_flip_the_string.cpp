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

        string A, B;
        cin >> A >> B;

        int N = A.size();

        const int MAX_BITS = 100000+7;
        bitset<MAX_BITS> A_bs(A);
        bitset<MAX_BITS> B_bs(B);

        bitset<MAX_BITS> C = A_bs ^ B_bs;

        int start = MAX_BITS - 1;
        int stop = MAX_BITS - (N-1);

        bitset<MAX_BITS> odd;
        bitset<MAX_BITS> even;
        int index_o = 0;
        int index_e = 0;
        for(int i = 0; i < N; i++) {
            if(i % 2 != 0) {
                if(C[i] == 1) {
                    odd[index_o] = 1;
                    index_o++;
                } else {
                    odd[index_o] = 0;
                    index_o++;  
                }
            } else {
                if(C[i] == 1) {
                    even[index_e] = 1;
                    index_e++;
                } else {
                    odd[index_e] = 0;
                    index_e++;    
                }
            }
        }

        int groups = 0;
        bool in_group = false;
        for(int i = 0; i < N; i++) {
            if(odd[i] == 1 && in_group == false) {
                in_group = true;
            } else if (odd[i] == 0 && in_group == true) {
                in_group = false;
                groups++;
            } else if (odd[i] == 1 && in_group == true) {
                continue;
            } else if (odd[i] == 0 && in_group == false) {
                continue;
            }
        }

        in_group = false;
        for(int i = 0; i < N; i++) {
            if(even[i] == 1 && in_group == false) {
                in_group = true;
            } else if (even[i] == 0 && in_group == true) {
                in_group = false;
                groups++;
            } else if (even[i] == 1 && in_group == true) {
                continue;
            } else if (even[i] == 0 && in_group == false) {
                continue;
            }
        }

        cout << groups << "\n";
    }
}

