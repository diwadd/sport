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
    
        int N;
        cin >> N;
        vector<int> vec(N, 0);
    
        int min_ele = numeric_limits<int>::max();
        for(int i = 0; i < N; i++) {
            cin >> vec[i];
            min_ele = min(vec[i], min_ele);
        }
    
        int freq = 0;
        for(int i = 0; i < N; i++) {
            if(vec[i] == min_ele)
                freq++;
        }
    
        cout << (vec.size() - freq) << endl;
    }
}