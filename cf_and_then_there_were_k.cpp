#include <bits/stdc++.h> 
    
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
    
        int N;
        cin >> N;
    
        int k = max(0, int(floor(log2(N))));

        cout << int(pow(2, k)) - 1 << "\n";
    
    }
}