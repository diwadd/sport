#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {
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


int get_value(vector<char> &vec) {

    int v = 0;
    for(int i = 0; i < vec.size(); i++) {
        v = v + (vec[i] - '0'); 
    }

    return v;
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

        int N;
        scanf("%d", &N);

        int A_sum = 0;
        int B_sum = 0;
        for(int n = 0; n < N; n++) {
            int A_i, B_i;
            scanf("%d %d", &A_i, &B_i);

            string A_s = to_string(A_i);
            string B_s = to_string(B_i);

            vector<char> A_vec(A_s.begin(), A_s.end());
            vector<char> B_vec(B_s.begin(), B_s.end());

            int A_v = get_value(A_vec);
            int B_v = get_value(B_vec);

            if(A_v > B_v)
                A_sum = A_sum + 1;
            else if(A_v < B_v)
                B_sum = B_sum + 1;
            else {
                A_sum = A_sum + 1;
                B_sum = B_sum + 1; 
            }
        }

        if (A_sum > B_sum) {
            printf("0 %d\n", A_sum);
        } else if (A_sum < B_sum) {
            printf("1 %d\n", B_sum);
        } else if (A_sum == B_sum) {
            printf("2 %d\n", A_sum);
        }
    }

}