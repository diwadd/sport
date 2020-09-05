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
 
        int a, b;
        cin >> a >> b;
 
        int d = abs(a-b);
        int tens = d / 10;
        if(d % 10 == 0) {
            cout << tens << "\n";
        } else {
            cout << tens + 1 << "\n";
        }
    }
}