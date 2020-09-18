#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void find_mex(vector<int> &freq, int &max_sum) {

    for(int i = 0; i < freq.size(); i++) {
        if(freq[i] > 0) {
            freq[i]--;
        } else if(freq[i] == 0){
            // cout << "i: " << i << "\n";
            max_sum += i;
            break;
        }
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

        const int MAX_FREQ = 100 + 1;
        vector<int> a_vec(N, 0);
        vector<int> freq(MAX_FREQ, 0);
        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            freq[a]++;
        }

        // print_vector(freq);

        int max_sum = 0;
        find_mex(freq, max_sum);
        find_mex(freq, max_sum);

        cout << max_sum << "\n";

    }
}