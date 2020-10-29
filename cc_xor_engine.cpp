#include <bits/stdc++.h>
using namespace std;

inline int get_number_of_bits(int &xr, vector<int> &bits_set_table){

    int w = bits_set_table[xr & 0xff] + 
            bits_set_table[(xr >> 8) & 0xff] + 
            bits_set_table[(xr >> 16) & 0xff] + 
            bits_set_table[xr >> 24];
    return w;
}

inline pair<int, int> get_even_odd_pair(int &&p, vector<int> &v){

    int n = v.size();
    int even = 0;
    for(int k = 0; k < n; k++){
        int xr = v[k]^p;

        //int w = get_number_of_bits(xr, bits_set_table);
        xr ^= xr >> 16;
        xr ^= xr >> 8;
        xr ^= xr >> 4;
        xr ^= xr >> 2;
        xr ^= xr >> 1;
        bool w = (~xr) & 1;

        // int w =  __builtin_popcount(xr);
        //if(w % 2 == 0){
        if (w == true) {
            even++;
        }
    }
    return make_pair(even, n - even);
}

int main() {

    int P_MAX = 1e5+1;
    vector<int> w_table(P_MAX, -1);

    // vector<int> bits_set_table(256, 0);
    // for (int i=0; i<256; i++) {
    //     bits_set_table[i] = bits_set_table[i/2] + (i&1);
    // }

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){

        int n, q;
        // cin >> n >> q;
        scanf("%d",&n);
        scanf("%d",&q);
        vector<int> v(n, 0);
        for(int j = 0; j < n; j++){
            int vj;
            // cin >> vj;
            scanf("%d",&vj);
            v[j] = vj;
        }

        // Three has even number of bits
        pair<int,int> ep = get_even_odd_pair(3, v);

        for(int j = 0; j < q; j++){
            int p;
            // cin >> p;
            scanf("%d",&p);

            bool w;
            int pt = p;
            if (w_table[pt] == -1) {
                p ^= p >> 16;
                p ^= p >> 8;
                p ^= p >> 4;
                p ^= p >> 2;
                p ^= p >> 1;
                w = (~p) & 1;
                w_table[pt] = w;
            } else {
                w = w_table[pt];
            }
            // int w;
            // if (w_table[p] == -1) {
            //     w = get_number_of_bits(p, bits_set_table);
            //     // w = __builtin_popcount(p);
            //     w_table[p] = w;
            // } else {
            //     w = w_table[p];
            // }

            //if (w % 2 == 0){
            if (w == 1) {
                //cout << ep.first << " " << ep.second << endl;
                printf("%d %d\n", ep.first, ep.second);
            } else {
                //cout << ep.second << " " << ep.first << endl;
                printf("%d %d\n", ep.second, ep.first);
            }
        }
    }
}