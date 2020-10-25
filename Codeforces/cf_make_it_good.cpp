#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
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
            int a;
            cin >> a;
            a_vec[i] = a;
        }
 
        int marker = N - 1;
 
        while(marker > 0 and a_vec[marker - 1] >= a_vec[marker]){
            marker--;
        }
 
        while(marker > 0 and a_vec[marker - 1] <= a_vec[marker]){
            marker--;
        }
 
        cout << marker << "\n";
 
    }
}