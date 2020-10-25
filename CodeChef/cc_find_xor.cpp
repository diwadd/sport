#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        if(i != vec.size()-1)
            cout << vec[i] << " ";
        else
            cout << vec[i];
    }
    cout << "\n";
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    const lli TWO_20 = 1048576;
    const lli MAX_BITS = 20;
    for(int t = 0; t < T; t++) {

        lli N;
        cin >> N;

        cout << 1 << " " << TWO_20 << endl;
        lli S;
        cin >> S;

        lli for_zero = S - N*TWO_20;
        
        bitset<MAX_BITS> res(0);
        if(for_zero % 2 != 0)
            res[0] = 1;
        for(int i = 1; i <= MAX_BITS - 1; i++) {
            lli two_to_i = (1 << i);
            cout << 1 << " " << two_to_i << endl;
            lli S_i;
            cin >> S_i;

            lli n = (N + ((for_zero - S_i) / two_to_i)) / 2;
            if(n % 2 == 0)
                res[i] = 0;
            else
                res[i] = 1; 
        }
        cout << 2 << " " << res.to_ulong() << endl;
        int ver;
        cin >> ver;

    }
}