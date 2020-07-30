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
 
 
    for(int t = 1; t <= T; t++) {
 
        lli N;
        cin >> N;
 
        int max_number = 30;
        if(N <= max_number) {
            cout << "NO\n";
        } else if(N == 36) { // case when delta is 6
            cout << "YES\n"; 
            cout << "6 10 15 5\n";
        } else if (N == 40) { // case when delta is 10
            cout << "YES\n"; 
            cout << "10 14 15 1\n";
        } else if (N == 44) { // case when delta is 14
            cout << "YES\n"; 
            cout << "10 14 15 5\n";
        } else {
            int delta = N - max_number;
            cout << "YES\n"; 
            cout << "6 10 14 " << delta << "\n";
        }
 
    }
}